/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    pop_front.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_POP_FRONT_H
#define YETA_GUARD_POP_FRONT_H

#include <yeta/detail/always_void.h>

namespace yeta {

template<class Iterable, class=void>
struct pop_front
{};

template<class Iterable>
struct pop_front<Iterable, YETA_VOID(Iterable::type::pop_front)>
: Iterable::type::pop_front
{};

}

#endif