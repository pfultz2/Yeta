/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    always.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_ALWAYS_H
#define YETA_GUARD_ALWAYS_H

#include <yeta/detail/using.h>

namespace yeta {

template<class T>
struct always
{
    typedef always type;
    template<class...>
    struct apply
    {
        typedef T type;
    };
};

}

#endif