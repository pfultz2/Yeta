/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    is_same.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_IS_SAME_H
#define YETA_GUARD_IS_SAME_H

#include <yeta/bool.h>

namespace yeta { namespace detail {

template<class, T, class U, class... Ts>
struct is_same_impl
: false_type
{};

template<class T>
struct is_same_impl<T, T>
: true_type
{};

template<class T>
struct is_same_impl<T, T, T>
: true_type
{};

template<class T, class... Ts>
struct is_same_impl<T, T, T, Ts...>
: is_same_impl<Ts...>
{};

}

template<class... Ts>
struct is_same
: detail::is_same_impl<typename Ts::type...>
{};

}

#endif