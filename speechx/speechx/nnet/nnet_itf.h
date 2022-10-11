// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#pragma once

#include "base/basic_types.h"
#include "kaldi/base/kaldi-types.h"
#include "kaldi/matrix/kaldi-matrix.h"

namespace ppspeech {

struct NnetOut{
  // nnet out, maybe logprob or prob
  kaldi::Vector<kaldi::BaseFloat> logprobs;
  int32 vocab_dim;

  // nnet state. Only using in Attention model.
  std::vector<std::vector<kaldi::BaseFloat>> encoder_outs;

  NnetOut() : logprobs({}), vocab_dim(-1), encoder_outs({}) {} 
};


class NnetInterface {
  public:
    virtual void FeedForward(const kaldi::Vector<kaldi::BaseFloat>& features,
                             const int32& feature_dim,
                             NnetOut* out) = 0;
    virtual void Reset() = 0;
    virtual ~NnetInterface() {}
};

}  // namespace ppspeech
