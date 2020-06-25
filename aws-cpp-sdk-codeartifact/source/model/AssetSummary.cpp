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

#include <aws/codeartifact/model/AssetSummary.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace CodeArtifact
{
namespace Model
{

AssetSummary::AssetSummary() : 
    m_nameHasBeenSet(false),
    m_size(0),
    m_sizeHasBeenSet(false),
    m_hashesHasBeenSet(false)
{
}

AssetSummary::AssetSummary(JsonView jsonValue) : 
    m_nameHasBeenSet(false),
    m_size(0),
    m_sizeHasBeenSet(false),
    m_hashesHasBeenSet(false)
{
  *this = jsonValue;
}

AssetSummary& AssetSummary::operator =(JsonView jsonValue)
{
  if(jsonValue.ValueExists("name"))
  {
    m_name = jsonValue.GetString("name");

    m_nameHasBeenSet = true;
  }

  if(jsonValue.ValueExists("size"))
  {
    m_size = jsonValue.GetInt64("size");

    m_sizeHasBeenSet = true;
  }

  if(jsonValue.ValueExists("hashes"))
  {
    Aws::Map<Aws::String, JsonView> hashesJsonMap = jsonValue.GetObject("hashes").GetAllObjects();
    for(auto& hashesItem : hashesJsonMap)
    {
      m_hashes[HashAlgorithmMapper::GetHashAlgorithmForName(hashesItem.first)] = hashesItem.second.AsString();
    }
    m_hashesHasBeenSet = true;
  }

  return *this;
}

JsonValue AssetSummary::Jsonize() const
{
  JsonValue payload;

  if(m_nameHasBeenSet)
  {
   payload.WithString("name", m_name);

  }

  if(m_sizeHasBeenSet)
  {
   payload.WithInt64("size", m_size);

  }

  if(m_hashesHasBeenSet)
  {
   JsonValue hashesJsonMap;
   for(auto& hashesItem : m_hashes)
   {
     hashesJsonMap.WithString(HashAlgorithmMapper::GetNameForHashAlgorithm(hashesItem.first), hashesItem.second);
   }
   payload.WithObject("hashes", std::move(hashesJsonMap));

  }

  return payload;
}

} // namespace Model
} // namespace CodeArtifact
} // namespace Aws