/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    count_if.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_COUNT_IF_H
#define YETA_GUARD_COUNT_IF_H

#include <yeta/bind_back.h>
#include <yeta/fold.h>
#include <yeta/size_t.h>
#include <yeta/quote.h>
#include <yeta/strict.h>

namespace yeta {


namespace detail {

template<class State, class Val, class Fun>
YETA_USING_EVAL(count_if_fun, if_<apply<Fun, Val>, 
    decltype(State::type::value + yeta::size_t<1>()), 
    State
>);

}

template<class Iterable, class Fun>
YETA_USING(count_if,
 // yeta::fold<Iterable, yeta::size_t<0>, bind_back<strict<quote<detail::count_if_fun>>, Fun>>);
 yeta::fold<Iterable, bind_back<strict<quote<detail::count_if_fun>>, Fun>, yeta::size_t<0>>);

}

#endif