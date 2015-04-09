/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    eval.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_EVAL_H
#define YETA_GUARD_EVAL_H

#include <yeta/detail/using.h>
#include <yeta/detail/always_void.h>

namespace yeta {

template<class F>
YETA_USING(eval, F::type);

#define YETA_EVAL(F) typename F::type

#define YETA_USING_EVAL(F, ...) using F = yeta::lazy_eval<__VA_ARGS__> 

// Unboxed evaluation
template<class F, class=void>
struct lazy_eval
{};

template<class F>
struct lazy_eval<F, YETA_VOID(F::type)>
: F::type
{};

}

#endif