/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    apply.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_APPLY_H
#define YETA_GUARD_APPLY_H

#include <yeta/detail/using.h>

namespace yeta {

template <class F, class... Args>
YETA_USING(apply, F::type::template apply<Args...>);

template <class F, class... Args>
YETA_USING(apply_eval, apply<F, Args...>::type);

}

#endif