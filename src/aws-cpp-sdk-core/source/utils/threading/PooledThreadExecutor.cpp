/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/core/utils/threading/PooledThreadExecutor.h>
#include <aws/core/utils/threading/ThreadTask.h>
#include <thread>
#include <aws/crt/pthread_utils.h>

static const char* POOLED_CLASS_TAG = "PooledThreadExecutor";

using namespace Aws::Utils::Threading;

PooledThreadExecutor::PooledThreadExecutor(size_t poolSize, OverflowPolicy overflowPolicy, uint8_t* cpus, uint32_t cpus_size) :
    m_sync(0, poolSize), m_poolSize(poolSize), m_overflowPolicy(overflowPolicy)
{
    cpu_set_t cpuset;
    cpu_set_t* pset = nullptr;
    if (cpus) {
        pset = &cpuset;
        util_cpu_zero(&cpuset);
        for (uint32_t cpu = 0; cpu < cpus_size; ++cpu) {
            if ((cpus[cpu / 8] >> (cpu % 8)) & 1U) { util_set_cpu(cpu, &cpuset); }
        }
    }

    for (size_t index = 0; index < m_poolSize; ++index)
    {
        m_threadTaskHandles.push_back(Aws::New<ThreadTask>(POOLED_CLASS_TAG, *this, pset));
    }
}

PooledThreadExecutor::~PooledThreadExecutor()
{
    WaitUntilStopped();
}

void PooledThreadExecutor::WaitUntilStopped()
{
    {
        std::lock_guard<std::mutex> locker(m_queueLock);
        m_stopped = true;
    }
    for(auto threadTask : m_threadTaskHandles)
    {
        threadTask->StopProcessingWork();
    }

    m_sync.ReleaseAll();

    for (auto threadTask : m_threadTaskHandles)
    {
        Aws::Delete(threadTask);
    }
    m_threadTaskHandles.clear();

    while(m_tasks.size() > 0)
    {
        std::function<void()>* fn = m_tasks.front();
        m_tasks.pop();

        if(fn)
        {
            Aws::Delete(fn);
        }
    }
}

bool PooledThreadExecutor::SubmitToThread(std::function<void()>&& fn)
{
    //avoid the need to do copies inside the lock. Instead lets do a pointer push.
    std::function<void()>* fnCpy = Aws::New<std::function<void()>>(POOLED_CLASS_TAG, std::forward<std::function<void()>>(fn));

    {
        std::lock_guard<std::mutex> locker(m_queueLock);

        if (m_stopped || (m_overflowPolicy == OverflowPolicy::REJECT_IMMEDIATELY && m_tasks.size() >= m_poolSize))
        {
            Aws::Delete(fnCpy);
            return false;
        }

        m_tasks.push(fnCpy);
    }

    m_sync.Release();

    return true;
}

std::function<void()>* PooledThreadExecutor::PopTask()
{
    std::lock_guard<std::mutex> locker(m_queueLock);

    if (m_tasks.size() > 0)
    {
        std::function<void()>* fn = m_tasks.front();
        if (fn)
        {           
            m_tasks.pop();
            return fn;
        }
    }

    return nullptr;
}

bool PooledThreadExecutor::HasTasks() const
{
    std::lock_guard<std::mutex> locker(m_queueLock);
    return m_tasks.size() > 0;
}
