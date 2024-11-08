/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/core/utils/threading/ThreadTask.h>
#include <aws/core/utils/threading/PooledThreadExecutor.h>

using namespace Aws::Utils;
using namespace Aws::Utils::Threading;

ThreadTask::ThreadTask(PooledThreadExecutor& executor, cpu_set_t* pset) : m_continue(true), m_executor(executor), m_thread(std::bind(&ThreadTask::MainTaskRunner, this))
{
    if (pset) {
      int rc = pthread_setaffinity_np(m_thread.native_handle(), sizeof(cpu_set_t), pset); 
      (void)rc;
    }
}

ThreadTask::~ThreadTask()
{
    StopProcessingWork();
    m_thread.join();
}

void ThreadTask::MainTaskRunner()
{
    while (m_continue)
    {        
        while (m_continue && m_executor.HasTasks())
        {      
            auto fn = m_executor.PopTask();
            if(fn)
            {
                (*fn)();
                Aws::Delete(fn);               
            }
        }
     
        if(m_continue)
        {
            m_executor.m_sync.WaitOne();
        }
    }
}

void ThreadTask::StopProcessingWork()
{
    m_continue = false;
}
