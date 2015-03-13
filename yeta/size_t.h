/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    size_t.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_SIZE_T_H
#define YETA_GUARD_SIZE_T_H

namespace yeta {

#include <yeta/integral_constant.h>
#include <yeta/detail/using.h>

namespace yeta {

template<std::size_t S>
YETA_USING(std::size_t, S);

}

#endif