/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    list.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_LIST_H
#define YETA_GUARD_LIST_H

namespace yeta {

template<class... Ts>
struct list;

template<class T, class... Ts>
struct list<T, Ts...>
{
    typedef list type;

    struct clear
    {
        typedef list<> type;
    };

    struct front
    {
        typedef T type;
    };

    struct pop_front
    {
        typedef list<Ts...> type;
    };

    template<class X>
    struct push_front
    {
        typedef list<X, T, Ts...> type;
    };

    template<class X>
    struct push_back
    {
        typedef list<T, Ts..., X> type;
    };
};

template<>
struct list<>
{
    typedef list type;

    struct clear
    {
        typedef list<> type;
    };

    struct pop_front
    {
        typedef list<> type;
    };

    template<class X>
    struct push_front
    {
        typedef list<X> type;
    };

    template<class X>
    struct push_back
    {
        typedef list<X> type;
    };
};

// TODO: Specialize transform

}

#endif