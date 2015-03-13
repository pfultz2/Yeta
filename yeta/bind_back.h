/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    bind_back.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_BIND_BACK_H
#define YETA_GUARD_BIND_BACK_H

#include <yeta/detail/using.h>

namespace yeta {

template<template <class...> class C, class... Args>
struct bind_back
{
    typedef bind_back type;
    template<class... Ts>
    YETA_USING(apply, C<Ts..., Args...>);
};

}

#endif