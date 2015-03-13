/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    quote.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_QUOTE_H
#define YETA_GUARD_QUOTE_H

#include <yeta/detail/using.h>

namespace yeta {

template<template <class...> class C>
struct quote
{
    typedef quote type;
    template<class... Ts>
    YETA_USING(apply, C<Ts...>);
};

}

#endif