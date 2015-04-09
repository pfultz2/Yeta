/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    fold.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_FOLD_H
#define YETA_GUARD_FOLD_H

#include <yeta/detail/na.h>
#include <yeta/if.h>
#include <yeta/apply.h>
#include <yeta/empty.h>
#include <yeta/front.h>
#include <yeta/pop_front.h>

namespace yeta {

template<class Iterable, class Fun, class State=detail::na>
struct fold
: lazy_eval<if_<empty<Iterable>, 
    State,
    fold<pop_front<Iterable>, Fun, apply<Fun, State, front<Iterable>>>
>>
{};

template<class Iterable, class Fun>
struct fold<Iterable, Fun>
: fold<pop_front<Iterable>, Fun, front<Iterable>>
{};

}

#endif