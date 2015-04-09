/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    bind_front.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_BIND_FRONT_H
#define YETA_GUARD_BIND_FRONT_H

#include <yeta/detail/using.h>

namespace yeta {

template<class F, class... Args>
struct bind_front
{
    typedef bind_front type;
    template<class... Ts>
    YETA_USING(apply, F::template apply<Args..., Ts...>);
};

}

#endif