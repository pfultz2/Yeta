/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    fold.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_FOLD_H
#define YETA_GUARD_FOLD_H

#include <yeta/detail/na.h>
#include <yeta/detail/requires.h>
#include <yeta/if.h>
#include <yeta/apply.h>
#include <yeta/empty.h>
#include <yeta/front.h>
#include <yeta/pop_front.h>
#include <yeta/is_iterable.h>
#include <yeta/is_metafunction_class.h>

namespace yeta {

template<class Iterable, class Fun, class State=detail::na, class=void>
struct fold;

template<class Iterable, class Fun, class State>
struct fold<Iterable, Fun, State, YETA_REQUIRES(is_iterable<Iterable>() and is_metafunction_class<Fun>())>
: lazy_eval<if_<empty<Iterable>, 
    State,
    fold<pop_front<Iterable>, Fun, apply<Fun, State, front<Iterable>>>
>>
{};

template<class Iterable, class Fun>
struct fold<Iterable, Fun, detail::na, YETA_REQUIRES(is_iterable<Iterable>() and is_metafunction_class<Fun>())>
: fold<pop_front<Iterable>, Fun, front<Iterable>>
{};

}

#endif