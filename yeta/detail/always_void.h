/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    always_void.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_ALWAYS_VOID_H
#define YETA_GUARD_ALWAYS_VOID_H

namespace yeta { namespace detail {

template<class...>
struct always_void
{
    typedef void type;
};
}}

#define YETA_VOID(...) typename yeta::detail::always_void<__VA_ARGS__>::type

#endif