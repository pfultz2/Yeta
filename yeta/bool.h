/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    bool.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_BOOL_H
#define YETA_GUARD_BOOL_H

#include <yeta/integral_constant.h>
#include <yeta/detail/using.h>

namespace yeta {

template<bool B>
YETA_USING(bool_, yeta::integral_constant<bool, B>);

typedef bool_<true> true_type;
typedef bool_<false> false_type;


}

#endif