/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    strict.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_STRICT_H
#define YETA_GUARD_STRICT_H

#include <yeta/apply.h>
#include <yeta/detail/using.h>
#include <yeta/detail/always_void.h>

namespace yeta {

namespace detail {

template<class F, class Args, class=void>
struct strict_apply_impl
{};

template<class F, class... Args>
struct strict_apply_impl<F, always_void<Args...>, YETA_VOID(apply<F, typename Args::type...>)>
: apply<F, typename Args::type...>
{};

}

template<class MetafunctionClass>
struct strict
{
    typedef strict type;
    template<class... Ts>
    struct apply
    : detail::strict_apply_impl<F, detail::always_void<Ts...>>
    {};
};

}

#endif