/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    lazy.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_LAZY_H
#define YETA_GUARD_LAZY_H

#include <yeta/apply.h>
#include <yeta/id.h>

namespace yeta {

template<class MetafunctionClass>
struct lazy
{
    typedef lazy type;
    template<class... Ts>
    struct apply
    : apply<MetafunctionClass, id<Ts>...>
    {};
};

}

#endif