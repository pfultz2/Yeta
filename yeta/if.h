/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    if.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_IF_H
#define YETA_GUARD_IF_H

#include <type_traits>
#include <yeta/id.h>
#include <yeta/or.h>
#include <yeta/eval.h>

namespace yeta {

namespace detail
{
struct no_else {};
}

template<class C, class T, class E = detail::no_else>
struct if_;

template<bool C, class T = void, class E = detail::no_else>
struct if_c;

namespace detail
{

template<bool C, class T>
struct if_c_clause
{
    template<bool C1, class T1 = void, class E1 = no_else>
    struct else_if_c
    : if_c<C || C1, typename if_c<C, T, T1>::type, E1> {};

    template<class E>
    struct else_: if_c<C, T, E> {};
};

template<class C, class BoxT>
struct if_clause
{
    template<class C1, class T1, class E = no_else>
    struct else_if: lazy_eval<if_<C, BoxT, if_<C, T1, E>>> {};

    template<class C1, class T1>
    struct else_if<C1, T1, no_else>
    : if_clause<or_<C, C1>, lazy_eval<if_<C, BoxT, id<T1>>>>
    {};

    template<class E>
    YETA_USING_EVAL(else_, if_<C, BoxT, id<E>>);
};

}

template<bool B, class T, class E>
struct if_c
: std::conditional<B, T, E> 
{};

template<class T>
struct if_c<false, T, detail::no_else>
: detail::if_c_clause<false, T> {};

template<class T>
struct if_c<true, T, detail::no_else> 
: detail::if_c_clause<true, T> 
{
    typedef T type;
};

template<class C, class T, class E>
struct if_: if_c<C::type::value, T, E> {};

template<class C, class T>
struct if_<C, T, detail::no_else>
: detail::if_clause<C, id<T>> 
{};

}

#endif