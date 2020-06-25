﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#pragma once
#include <aws/compute-optimizer/ComputeOptimizer_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/compute-optimizer/model/S3Destination.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace ComputeOptimizer
{
namespace Model
{
  class AWS_COMPUTEOPTIMIZER_API ExportAutoScalingGroupRecommendationsResult
  {
  public:
    ExportAutoScalingGroupRecommendationsResult();
    ExportAutoScalingGroupRecommendationsResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    ExportAutoScalingGroupRecommendationsResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * <p>The identification number of the export job.</p> <p>Use the
     * <code>DescribeRecommendationExportJobs</code> action, and specify the job ID to
     * view the status of an export job.</p>
     */
    inline const Aws::String& GetJobId() const{ return m_jobId; }

    /**
     * <p>The identification number of the export job.</p> <p>Use the
     * <code>DescribeRecommendationExportJobs</code> action, and specify the job ID to
     * view the status of an export job.</p>
     */
    inline void SetJobId(const Aws::String& value) { m_jobId = value; }

    /**
     * <p>The identification number of the export job.</p> <p>Use the
     * <code>DescribeRecommendationExportJobs</code> action, and specify the job ID to
     * view the status of an export job.</p>
     */
    inline void SetJobId(Aws::String&& value) { m_jobId = std::move(value); }

    /**
     * <p>The identification number of the export job.</p> <p>Use the
     * <code>DescribeRecommendationExportJobs</code> action, and specify the job ID to
     * view the status of an export job.</p>
     */
    inline void SetJobId(const char* value) { m_jobId.assign(value); }

    /**
     * <p>The identification number of the export job.</p> <p>Use the
     * <code>DescribeRecommendationExportJobs</code> action, and specify the job ID to
     * view the status of an export job.</p>
     */
    inline ExportAutoScalingGroupRecommendationsResult& WithJobId(const Aws::String& value) { SetJobId(value); return *this;}

    /**
     * <p>The identification number of the export job.</p> <p>Use the
     * <code>DescribeRecommendationExportJobs</code> action, and specify the job ID to
     * view the status of an export job.</p>
     */
    inline ExportAutoScalingGroupRecommendationsResult& WithJobId(Aws::String&& value) { SetJobId(std::move(value)); return *this;}

    /**
     * <p>The identification number of the export job.</p> <p>Use the
     * <code>DescribeRecommendationExportJobs</code> action, and specify the job ID to
     * view the status of an export job.</p>
     */
    inline ExportAutoScalingGroupRecommendationsResult& WithJobId(const char* value) { SetJobId(value); return *this;}


    /**
     * <p>An object that describes the destination Amazon S3 bucket of a
     * recommendations export file.</p>
     */
    inline const S3Destination& GetS3Destination() const{ return m_s3Destination; }

    /**
     * <p>An object that describes the destination Amazon S3 bucket of a
     * recommendations export file.</p>
     */
    inline void SetS3Destination(const S3Destination& value) { m_s3Destination = value; }

    /**
     * <p>An object that describes the destination Amazon S3 bucket of a
     * recommendations export file.</p>
     */
    inline void SetS3Destination(S3Destination&& value) { m_s3Destination = std::move(value); }

    /**
     * <p>An object that describes the destination Amazon S3 bucket of a
     * recommendations export file.</p>
     */
    inline ExportAutoScalingGroupRecommendationsResult& WithS3Destination(const S3Destination& value) { SetS3Destination(value); return *this;}

    /**
     * <p>An object that describes the destination Amazon S3 bucket of a
     * recommendations export file.</p>
     */
    inline ExportAutoScalingGroupRecommendationsResult& WithS3Destination(S3Destination&& value) { SetS3Destination(std::move(value)); return *this;}

  private:

    Aws::String m_jobId;

    S3Destination m_s3Destination;
  };

} // namespace Model
} // namespace ComputeOptimizer
} // namespace Aws