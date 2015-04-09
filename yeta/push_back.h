/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    push_back.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_PUSH_BACK_H
#define YETA_GUARD_PUSH_BACK_H

#include <yeta/detail/always_void.h>

namespace yeta {

template<class Iterable, class X, class=void>
struct push_back
{};

template<class Iterable, class X>
struct push_back<Iterable, X, YETA_VOID(Iterable::type::template push_back<typename X::type>)>
: Iterable::type::template push_back<typename X::type>
{};

}

#endif