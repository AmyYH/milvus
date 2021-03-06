// Copyright (C) 2019-2020 Zilliz. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance
// with the License. You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied. See the License for the specific language governing permissions and limitations under the License.

#pragma once

#include "server/delivery/request/BaseReq.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace milvus {
namespace server {

class InsertReq : public BaseReq {
 public:
    static BaseReqPtr
    Create(const ContextPtr& context, const std::string& collection_name, const std::string& partition_name,
           const int64_t& row_count, std::unordered_map<std::string, std::vector<uint8_t>>& chunk_data);

 protected:
    InsertReq(const ContextPtr& context, const std::string& collection_name, const std::string& partition_name,
              const int64_t& row_count, std::unordered_map<std::string, std::vector<uint8_t>>& chunk_data);

    Status
    OnExecute() override;

 private:
    const std::string collection_name_;
    const std::string partition_name_;
    const int64_t row_count_;
    std::unordered_map<std::string, std::vector<uint8_t>>& chunk_data_;
};

}  // namespace server
}  // namespace milvus
