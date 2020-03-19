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
#include <aws/appmesh/AppMesh_EXPORTS.h>
#include <aws/appmesh/model/ClientPolicy.h>
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
namespace AppMesh
{
namespace Model
{

  /**
   * <p>An object that represents the default properties for a backend.</p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/appmesh-2019-01-25/BackendDefaults">AWS
   * API Reference</a></p>
   */
  class AWS_APPMESH_API BackendDefaults
  {
  public:
    BackendDefaults();
    BackendDefaults(Aws::Utils::Json::JsonView jsonValue);
    BackendDefaults& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>A reference to an object that represents a client policy.</p>
     */
    inline const ClientPolicy& GetClientPolicy() const{ return m_clientPolicy; }

    /**
     * <p>A reference to an object that represents a client policy.</p>
     */
    inline bool ClientPolicyHasBeenSet() const { return m_clientPolicyHasBeenSet; }

    /**
     * <p>A reference to an object that represents a client policy.</p>
     */
    inline void SetClientPolicy(const ClientPolicy& value) { m_clientPolicyHasBeenSet = true; m_clientPolicy = value; }

    /**
     * <p>A reference to an object that represents a client policy.</p>
     */
    inline void SetClientPolicy(ClientPolicy&& value) { m_clientPolicyHasBeenSet = true; m_clientPolicy = std::move(value); }

    /**
     * <p>A reference to an object that represents a client policy.</p>
     */
    inline BackendDefaults& WithClientPolicy(const ClientPolicy& value) { SetClientPolicy(value); return *this;}

    /**
     * <p>A reference to an object that represents a client policy.</p>
     */
    inline BackendDefaults& WithClientPolicy(ClientPolicy&& value) { SetClientPolicy(std::move(value)); return *this;}

  private:

    ClientPolicy m_clientPolicy;
    bool m_clientPolicyHasBeenSet;
  };

} // namespace Model
} // namespace AppMesh
} // namespace Aws