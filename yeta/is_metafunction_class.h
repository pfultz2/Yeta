/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    is_metafunction_class.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_IS_METAFUNCTION_CLASS_H
#define YETA_GUARD_IS_METAFUNCTION_CLASS_H

#include <yeta/bool.h>

namespace yeta {

namespace detail {

template<template<class...> class T>
struct always_template_void
{
    typedef void type;
};

}

template<class MetafunctionClass, class=void>
struct is_metafunction_class
: yeta::bool_<false>
{};

template<class MetafunctionClass>
struct is_metafunction_class<MetafunctionClass, typename detail::always_template_void<
    MetafunctionClass::template apply
>::type>
: yeta::bool_<true>
{};

}

#endif
