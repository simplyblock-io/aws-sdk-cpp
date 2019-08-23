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
#include <aws/forecast/ForecastService_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/forecast/model/FilterConditionString.h>
#include <utility>

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
namespace ForecastService
{
namespace Model
{

  /**
   * <p>Describes a filter for choosing a subset of objects. Each filter consists of
   * a condition and a match statement. The condition is either <code>IS</code> or
   * <code>IS_NOT</code>, which specifies whether to include or exclude,
   * respectively, the objects that match the statement. The match statement consists
   * of a key and a value.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/forecast-2018-06-26/Filter">AWS API
   * Reference</a></p>
   */
  class AWS_FORECASTSERVICE_API Filter
  {
  public:
    Filter();
    Filter(Aws::Utils::Json::JsonView jsonValue);
    Filter& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The name of the parameter to filter on.</p>
     */
    inline const Aws::String& GetKey() const{ return m_key; }

    /**
     * <p>The name of the parameter to filter on.</p>
     */
    inline bool KeyHasBeenSet() const { return m_keyHasBeenSet; }

    /**
     * <p>The name of the parameter to filter on.</p>
     */
    inline void SetKey(const Aws::String& value) { m_keyHasBeenSet = true; m_key = value; }

    /**
     * <p>The name of the parameter to filter on.</p>
     */
    inline void SetKey(Aws::String&& value) { m_keyHasBeenSet = true; m_key = std::move(value); }

    /**
     * <p>The name of the parameter to filter on.</p>
     */
    inline void SetKey(const char* value) { m_keyHasBeenSet = true; m_key.assign(value); }

    /**
     * <p>The name of the parameter to filter on.</p>
     */
    inline Filter& WithKey(const Aws::String& value) { SetKey(value); return *this;}

    /**
     * <p>The name of the parameter to filter on.</p>
     */
    inline Filter& WithKey(Aws::String&& value) { SetKey(std::move(value)); return *this;}

    /**
     * <p>The name of the parameter to filter on.</p>
     */
    inline Filter& WithKey(const char* value) { SetKey(value); return *this;}


    /**
     * <p>A valid value for <code>Key</code>.</p>
     */
    inline const Aws::String& GetValue() const{ return m_value; }

    /**
     * <p>A valid value for <code>Key</code>.</p>
     */
    inline bool ValueHasBeenSet() const { return m_valueHasBeenSet; }

    /**
     * <p>A valid value for <code>Key</code>.</p>
     */
    inline void SetValue(const Aws::String& value) { m_valueHasBeenSet = true; m_value = value; }

    /**
     * <p>A valid value for <code>Key</code>.</p>
     */
    inline void SetValue(Aws::String&& value) { m_valueHasBeenSet = true; m_value = std::move(value); }

    /**
     * <p>A valid value for <code>Key</code>.</p>
     */
    inline void SetValue(const char* value) { m_valueHasBeenSet = true; m_value.assign(value); }

    /**
     * <p>A valid value for <code>Key</code>.</p>
     */
    inline Filter& WithValue(const Aws::String& value) { SetValue(value); return *this;}

    /**
     * <p>A valid value for <code>Key</code>.</p>
     */
    inline Filter& WithValue(Aws::String&& value) { SetValue(std::move(value)); return *this;}

    /**
     * <p>A valid value for <code>Key</code>.</p>
     */
    inline Filter& WithValue(const char* value) { SetValue(value); return *this;}


    /**
     * <p>The condition to apply.</p>
     */
    inline const FilterConditionString& GetCondition() const{ return m_condition; }

    /**
     * <p>The condition to apply.</p>
     */
    inline bool ConditionHasBeenSet() const { return m_conditionHasBeenSet; }

    /**
     * <p>The condition to apply.</p>
     */
    inline void SetCondition(const FilterConditionString& value) { m_conditionHasBeenSet = true; m_condition = value; }

    /**
     * <p>The condition to apply.</p>
     */
    inline void SetCondition(FilterConditionString&& value) { m_conditionHasBeenSet = true; m_condition = std::move(value); }

    /**
     * <p>The condition to apply.</p>
     */
    inline Filter& WithCondition(const FilterConditionString& value) { SetCondition(value); return *this;}

    /**
     * <p>The condition to apply.</p>
     */
    inline Filter& WithCondition(FilterConditionString&& value) { SetCondition(std::move(value)); return *this;}

  private:

    Aws::String m_key;
    bool m_keyHasBeenSet;

    Aws::String m_value;
    bool m_valueHasBeenSet;

    FilterConditionString m_condition;
    bool m_conditionHasBeenSet;
  };

} // namespace Model
} // namespace ForecastService
} // namespace Aws