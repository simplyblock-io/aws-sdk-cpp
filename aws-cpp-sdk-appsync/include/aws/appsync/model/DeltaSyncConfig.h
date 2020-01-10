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
#include <aws/appsync/AppSync_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>
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
namespace AppSync
{
namespace Model
{

  /**
   * <p>Describes a Delta Sync configuration.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/appsync-2017-07-25/DeltaSyncConfig">AWS
   * API Reference</a></p>
   */
  class AWS_APPSYNC_API DeltaSyncConfig
  {
  public:
    DeltaSyncConfig();
    DeltaSyncConfig(Aws::Utils::Json::JsonView jsonValue);
    DeltaSyncConfig& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The number of minutes an Item is stored in the datasource.</p>
     */
    inline long long GetBaseTableTTL() const{ return m_baseTableTTL; }

    /**
     * <p>The number of minutes an Item is stored in the datasource.</p>
     */
    inline bool BaseTableTTLHasBeenSet() const { return m_baseTableTTLHasBeenSet; }

    /**
     * <p>The number of minutes an Item is stored in the datasource.</p>
     */
    inline void SetBaseTableTTL(long long value) { m_baseTableTTLHasBeenSet = true; m_baseTableTTL = value; }

    /**
     * <p>The number of minutes an Item is stored in the datasource.</p>
     */
    inline DeltaSyncConfig& WithBaseTableTTL(long long value) { SetBaseTableTTL(value); return *this;}


    /**
     * <p>The Delta Sync table name.</p>
     */
    inline const Aws::String& GetDeltaSyncTableName() const{ return m_deltaSyncTableName; }

    /**
     * <p>The Delta Sync table name.</p>
     */
    inline bool DeltaSyncTableNameHasBeenSet() const { return m_deltaSyncTableNameHasBeenSet; }

    /**
     * <p>The Delta Sync table name.</p>
     */
    inline void SetDeltaSyncTableName(const Aws::String& value) { m_deltaSyncTableNameHasBeenSet = true; m_deltaSyncTableName = value; }

    /**
     * <p>The Delta Sync table name.</p>
     */
    inline void SetDeltaSyncTableName(Aws::String&& value) { m_deltaSyncTableNameHasBeenSet = true; m_deltaSyncTableName = std::move(value); }

    /**
     * <p>The Delta Sync table name.</p>
     */
    inline void SetDeltaSyncTableName(const char* value) { m_deltaSyncTableNameHasBeenSet = true; m_deltaSyncTableName.assign(value); }

    /**
     * <p>The Delta Sync table name.</p>
     */
    inline DeltaSyncConfig& WithDeltaSyncTableName(const Aws::String& value) { SetDeltaSyncTableName(value); return *this;}

    /**
     * <p>The Delta Sync table name.</p>
     */
    inline DeltaSyncConfig& WithDeltaSyncTableName(Aws::String&& value) { SetDeltaSyncTableName(std::move(value)); return *this;}

    /**
     * <p>The Delta Sync table name.</p>
     */
    inline DeltaSyncConfig& WithDeltaSyncTableName(const char* value) { SetDeltaSyncTableName(value); return *this;}


    /**
     * <p>The number of minutes a Delta Sync log entry is stored in the Delta Sync
     * table.</p>
     */
    inline long long GetDeltaSyncTableTTL() const{ return m_deltaSyncTableTTL; }

    /**
     * <p>The number of minutes a Delta Sync log entry is stored in the Delta Sync
     * table.</p>
     */
    inline bool DeltaSyncTableTTLHasBeenSet() const { return m_deltaSyncTableTTLHasBeenSet; }

    /**
     * <p>The number of minutes a Delta Sync log entry is stored in the Delta Sync
     * table.</p>
     */
    inline void SetDeltaSyncTableTTL(long long value) { m_deltaSyncTableTTLHasBeenSet = true; m_deltaSyncTableTTL = value; }

    /**
     * <p>The number of minutes a Delta Sync log entry is stored in the Delta Sync
     * table.</p>
     */
    inline DeltaSyncConfig& WithDeltaSyncTableTTL(long long value) { SetDeltaSyncTableTTL(value); return *this;}

  private:

    long long m_baseTableTTL;
    bool m_baseTableTTLHasBeenSet;

    Aws::String m_deltaSyncTableName;
    bool m_deltaSyncTableNameHasBeenSet;

    long long m_deltaSyncTableTTL;
    bool m_deltaSyncTableTTLHasBeenSet;
  };

} // namespace Model
} // namespace AppSync
} // namespace Aws