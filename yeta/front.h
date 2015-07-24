/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    front.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_FRONT_H
#define YETA_GUARD_FRONT_H

#include <yeta/detail/always_void.h>

namespace yeta {

template<class Iterable, class=void>
struct front
{};

template<class Iterable>
struct front<Iterable, YETA_VOID(Iterable::type::front)>
: Iterable::type::front
{
    typedef void yeta_front_tag;
};

}

#endif