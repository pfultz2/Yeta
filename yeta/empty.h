/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    empty.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_EMPTY_H
#define YETA_GUARD_EMPTY_H

#include <yeta/pop_front.h>
#include <yeta/is_same.h>
#include <yeta/detail/using.h>

namespace yeta {

template<class Iterable>
YETA_USING(empty, yeta::is_same<Iterable, pop_front<Iterable>>);

}

#endif