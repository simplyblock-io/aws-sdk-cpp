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
#include <aws/rekognition/Rekognition_EXPORTS.h>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace Rekognition
{
namespace Model
{

  /**
   * <p>A set of parameters that allow you to filter out certain results from your
   * returned results.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/rekognition-2016-06-27/DetectionFilter">AWS
   * API Reference</a></p>
   */
  class AWS_REKOGNITION_API DetectionFilter
  {
  public:
    DetectionFilter();
    DetectionFilter(Aws::Utils::Json::JsonView jsonValue);
    DetectionFilter& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>Sets confidence of word detection. Words with detection confidence below this
     * will be excluded from the result. Values should be between 0.5 and 1 as Text in
     * Video will not return any result below 0.5.</p>
     */
    inline double GetMinConfidence() const{ return m_minConfidence; }

    /**
     * <p>Sets confidence of word detection. Words with detection confidence below this
     * will be excluded from the result. Values should be between 0.5 and 1 as Text in
     * Video will not return any result below 0.5.</p>
     */
    inline bool MinConfidenceHasBeenSet() const { return m_minConfidenceHasBeenSet; }

    /**
     * <p>Sets confidence of word detection. Words with detection confidence below this
     * will be excluded from the result. Values should be between 0.5 and 1 as Text in
     * Video will not return any result below 0.5.</p>
     */
    inline void SetMinConfidence(double value) { m_minConfidenceHasBeenSet = true; m_minConfidence = value; }

    /**
     * <p>Sets confidence of word detection. Words with detection confidence below this
     * will be excluded from the result. Values should be between 0.5 and 1 as Text in
     * Video will not return any result below 0.5.</p>
     */
    inline DetectionFilter& WithMinConfidence(double value) { SetMinConfidence(value); return *this;}


    /**
     * <p>Sets the minimum height of the word bounding box. Words with bounding box
     * heights lesser than this value will be excluded from the result. Value is
     * relative to the video frame height.</p>
     */
    inline double GetMinBoundingBoxHeight() const{ return m_minBoundingBoxHeight; }

    /**
     * <p>Sets the minimum height of the word bounding box. Words with bounding box
     * heights lesser than this value will be excluded from the result. Value is
     * relative to the video frame height.</p>
     */
    inline bool MinBoundingBoxHeightHasBeenSet() const { return m_minBoundingBoxHeightHasBeenSet; }

    /**
     * <p>Sets the minimum height of the word bounding box. Words with bounding box
     * heights lesser than this value will be excluded from the result. Value is
     * relative to the video frame height.</p>
     */
    inline void SetMinBoundingBoxHeight(double value) { m_minBoundingBoxHeightHasBeenSet = true; m_minBoundingBoxHeight = value; }

    /**
     * <p>Sets the minimum height of the word bounding box. Words with bounding box
     * heights lesser than this value will be excluded from the result. Value is
     * relative to the video frame height.</p>
     */
    inline DetectionFilter& WithMinBoundingBoxHeight(double value) { SetMinBoundingBoxHeight(value); return *this;}


    /**
     * <p>Sets the minimum width of the word bounding box. Words with bounding boxes
     * widths lesser than this value will be excluded from the result. Value is
     * relative to the video frame width.</p>
     */
    inline double GetMinBoundingBoxWidth() const{ return m_minBoundingBoxWidth; }

    /**
     * <p>Sets the minimum width of the word bounding box. Words with bounding boxes
     * widths lesser than this value will be excluded from the result. Value is
     * relative to the video frame width.</p>
     */
    inline bool MinBoundingBoxWidthHasBeenSet() const { return m_minBoundingBoxWidthHasBeenSet; }

    /**
     * <p>Sets the minimum width of the word bounding box. Words with bounding boxes
     * widths lesser than this value will be excluded from the result. Value is
     * relative to the video frame width.</p>
     */
    inline void SetMinBoundingBoxWidth(double value) { m_minBoundingBoxWidthHasBeenSet = true; m_minBoundingBoxWidth = value; }

    /**
     * <p>Sets the minimum width of the word bounding box. Words with bounding boxes
     * widths lesser than this value will be excluded from the result. Value is
     * relative to the video frame width.</p>
     */
    inline DetectionFilter& WithMinBoundingBoxWidth(double value) { SetMinBoundingBoxWidth(value); return *this;}

  private:

    double m_minConfidence;
    bool m_minConfidenceHasBeenSet;

    double m_minBoundingBoxHeight;
    bool m_minBoundingBoxHeightHasBeenSet;

    double m_minBoundingBoxWidth;
    bool m_minBoundingBoxWidthHasBeenSet;
  };

} // namespace Model
} // namespace Rekognition
} // namespace Aws