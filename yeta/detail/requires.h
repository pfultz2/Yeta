/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    requires.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_DETAIL_REQUIRES_H
#define YETA_GUARD_DETAIL_REQUIRES_H

#include <type_traits>

#define YETA_REQUIRES(...) typename std::enable_if<(__VA_ARGS__)>::type

#endif
