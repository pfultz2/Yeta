/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    is_iterable.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_IS_ITERABLE_H
#define YETA_GUARD_IS_ITERABLE_H

#include <yeta/pop_front.h>
#include <yeta/front.h>
#include <yeta/bool.h>
#include <yeta/detail/always_void.h>

namespace yeta {

template<class Iterable, class=void>
struct is_iterable
: yeta::bool_<false>
{};

template<class Iterable>
struct is_iterable<Iterable, typename detail::always_void<
    typename front<Iterable>::yeta_front_tag,
    typename pop_front<Iterable>::type
>::type>
: yeta::bool_<true>
{};

}

#endif
