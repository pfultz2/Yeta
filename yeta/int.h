/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    int.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_INT_H
#define YETA_GUARD_INT_H

#include <yeta/integral_constant.h>
#include <yeta/detail/using.h>

namespace yeta {

template<int N>
YETA_USING(int_, yeta::integral_constant<int, N>);

}

#endif