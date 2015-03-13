/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    or.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_OR_H
#define YETA_GUARD_OR_H

#include <yeta/bool.h>
#include <yeta/eval.h>

namespace yeta {

namespace detail {
template <typename ...T>
false_ or_impl(T*...);
true_ or_impl(...);
}

template <bool... Bs>
struct or_c
: true_
{};

template <>
struct or_c<false, false>
: false_
{};

template <>
struct or_c<false>
: false_
{};

template <>
struct or_c<>
: false_
{};

template <bool ...Bs>
struct or_c<false, false, Bs...>
: decltype(detail::or_impl(
        typename std::conditional<Bs, int, int*>::type{}...
    )
)
{};


template <class... Fs>
struct or_
: or_c<Fs::type::value...>
{};

template <class F1, class F2>
struct or_<F1, F2>
: lazy_eval<std::conditional<F1::type::value, true_, F2>>
{};

}

#endif