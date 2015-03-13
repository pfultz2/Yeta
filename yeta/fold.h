/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    fold.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_FOLD_H
#define YETA_GUARD_FOLD_H

#include <yeta/if.h>
#include <yeta/lazy_apply.h>
#include <yeta/empty.h>
#include <yeta/front.h>
#include <yeta/pop_front.h>

namespace yeta {

template<class Iterable, class State, class Fun>
YETA_USING_EVAL(fold, if_<empty<Iterable>, 
    State,
    fold<pop_front<Iterable>, apply<Fun, State, front<Iterable>>, Fun>
>);

}

#endif