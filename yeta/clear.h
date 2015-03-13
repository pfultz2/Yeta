/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    clear.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_CLEAR_H
#define YETA_GUARD_CLEAR_H

#include <yeta/detail/always_void.h>

namespace yeta {

template<class Iterable, class=void>
struct clear
{};

template<class Iterable>
struct clear<Iterable, YETA_VOID(typename Iterable::type::clear)>
: Iterable::type::clear
{};

}

#endif