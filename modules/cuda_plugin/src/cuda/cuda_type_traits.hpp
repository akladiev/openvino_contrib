// Copyright (C) 2018-2021 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once
#include <cuda_runtime_api.h>

#include <ngraph/type/element_type_traits.hpp>
#ifdef __CUDACC__
#include <cuda_bf16.h>
#include <cuda_fp16.h>
#endif

namespace CUDA {

template <ngraph::element::Type_t Type>
struct cuda_type_traits : ngraph::element_type_traits<Type> {};

#ifdef __CUDACC__
template <>
struct cuda_type_traits<ngraph::element::Type_t::f16> { /* 5bit exponent, 10bit mantissa */
    using value_type = __half;                          // 16-bit half-precision floating point (FP16) representation:
                                                        // 1 sign bit, 5 exponent bits, and 10 mantissa bits.
};

template <>
struct cuda_type_traits<ngraph::element::Type_t::bf16> { /* 8bit exponent, 7bit mantissa */
    using value_type = __nv_bfloat16;
};

#endif
}  // namespace CUDA