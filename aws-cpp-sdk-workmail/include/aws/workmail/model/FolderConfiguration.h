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
#include <aws/workmail/WorkMail_EXPORTS.h>
#include <aws/workmail/model/FolderName.h>
#include <aws/workmail/model/RetentionAction.h>
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
namespace WorkMail
{
namespace Model
{

  /**
   * <p>The configuration applied to an organization's folders by its retention
   * policy.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/workmail-2017-10-01/FolderConfiguration">AWS
   * API Reference</a></p>
   */
  class AWS_WORKMAIL_API FolderConfiguration
  {
  public:
    FolderConfiguration();
    FolderConfiguration(Aws::Utils::Json::JsonView jsonValue);
    FolderConfiguration& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The folder name.</p>
     */
    inline const FolderName& GetName() const{ return m_name; }

    /**
     * <p>The folder name.</p>
     */
    inline bool NameHasBeenSet() const { return m_nameHasBeenSet; }

    /**
     * <p>The folder name.</p>
     */
    inline void SetName(const FolderName& value) { m_nameHasBeenSet = true; m_name = value; }

    /**
     * <p>The folder name.</p>
     */
    inline void SetName(FolderName&& value) { m_nameHasBeenSet = true; m_name = std::move(value); }

    /**
     * <p>The folder name.</p>
     */
    inline FolderConfiguration& WithName(const FolderName& value) { SetName(value); return *this;}

    /**
     * <p>The folder name.</p>
     */
    inline FolderConfiguration& WithName(FolderName&& value) { SetName(std::move(value)); return *this;}


    /**
     * <p>The action to take on the folder contents at the end of the folder
     * configuration period.</p>
     */
    inline const RetentionAction& GetAction() const{ return m_action; }

    /**
     * <p>The action to take on the folder contents at the end of the folder
     * configuration period.</p>
     */
    inline bool ActionHasBeenSet() const { return m_actionHasBeenSet; }

    /**
     * <p>The action to take on the folder contents at the end of the folder
     * configuration period.</p>
     */
    inline void SetAction(const RetentionAction& value) { m_actionHasBeenSet = true; m_action = value; }

    /**
     * <p>The action to take on the folder contents at the end of the folder
     * configuration period.</p>
     */
    inline void SetAction(RetentionAction&& value) { m_actionHasBeenSet = true; m_action = std::move(value); }

    /**
     * <p>The action to take on the folder contents at the end of the folder
     * configuration period.</p>
     */
    inline FolderConfiguration& WithAction(const RetentionAction& value) { SetAction(value); return *this;}

    /**
     * <p>The action to take on the folder contents at the end of the folder
     * configuration period.</p>
     */
    inline FolderConfiguration& WithAction(RetentionAction&& value) { SetAction(std::move(value)); return *this;}


    /**
     * <p>The period of time at which the folder configuration action is applied.</p>
     */
    inline int GetPeriod() const{ return m_period; }

    /**
     * <p>The period of time at which the folder configuration action is applied.</p>
     */
    inline bool PeriodHasBeenSet() const { return m_periodHasBeenSet; }

    /**
     * <p>The period of time at which the folder configuration action is applied.</p>
     */
    inline void SetPeriod(int value) { m_periodHasBeenSet = true; m_period = value; }

    /**
     * <p>The period of time at which the folder configuration action is applied.</p>
     */
    inline FolderConfiguration& WithPeriod(int value) { SetPeriod(value); return *this;}

  private:

    FolderName m_name;
    bool m_nameHasBeenSet;

    RetentionAction m_action;
    bool m_actionHasBeenSet;

    int m_period;
    bool m_periodHasBeenSet;
  };

} // namespace Model
} // namespace WorkMail
} // namespace Aws