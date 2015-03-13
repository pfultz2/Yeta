/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    push_front.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_PUSH_FRONT_H
#define YETA_GUARD_PUSH_FRONT_H

#include <yeta/detail/always_void.h>

namespace yeta {

template<class Iterable, class X, class=void>
struct push_front
{};

template<class Iterablem class X>
struct push_front<Iterable, X, YETA_VOID(typename Iterable::type::push_front<typename X::type>)>
: Iterable::type::push_front<typename X::type>
{};

}

#endif