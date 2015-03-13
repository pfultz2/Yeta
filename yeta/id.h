/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    id.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_ID_H
#define YETA_GUARD_ID_H

namespace yeta {

template<class T>
struct id
{
    typedef T type;
};

}

#endif