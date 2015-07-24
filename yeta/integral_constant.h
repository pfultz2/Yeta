/*=============================================================================
    Copyright (c) 2015 Paul Fultz II
    integral_constant.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef YETA_GUARD_INTEGRAL_CONSTANT_H
#define YETA_GUARD_INTEGRAL_CONSTANT_H

#include <type_traits>

namespace yeta {

namespace detail {
struct integral_constant_base {};
}

template<class T, T v>
struct integral_constant
: std::integral_constant<T, v>, detail::integral_constant_base
{
    constexpr integral_constant()
    {}

    template<class X, typename std::enable_if<(
        std::is_same<T, typename X::value_type>::value and X::value == v
    )>::type>
    constexpr integral_constant(X)
    {}

    constexpr T operator()() const noexcept { return v; }

    typedef integral_constant type;
};

#define YETA_INTEGRAL_CONSTANT_BINARY_OP(op) \
template<class T, T v, class U, U w> \
constexpr inline integral_constant<decltype(v op w), (v op w)> \
operator op(integral_constant<T, v>, integral_constant<U, w>) noexcept \
{ \
    return {}; \
} \
template<class T, T v, class U, class=typename std::enable_if<!std::is_base_of<detail::integral_constant_base, U>::value>::type> \
constexpr inline integral_constant<decltype(v op U::value), (v op U::value)> \
operator op(integral_constant<T, v>, U) noexcept \
{ \
    return {}; \
} \
template<class T, T v, class U, class=typename std::enable_if<!std::is_base_of<detail::integral_constant_base, U>::value>::type> \
constexpr inline integral_constant<decltype(U::value op v), (U::value op v)> \
operator op(U, integral_constant<T, v>) noexcept \
{ \
    return {}; \
}

#define YETA_INTEGRAL_CONSTANT_UNARY_OP(op) \
template<class T, T v> \
constexpr inline integral_constant<decltype(op v), (op v)> \
operator op(integral_constant<T, v>) noexcept \
{ \
    return {}; \
}

YETA_INTEGRAL_CONSTANT_BINARY_OP(+)
YETA_INTEGRAL_CONSTANT_BINARY_OP(-)
YETA_INTEGRAL_CONSTANT_BINARY_OP(*)
YETA_INTEGRAL_CONSTANT_BINARY_OP(/)
YETA_INTEGRAL_CONSTANT_BINARY_OP(%)
YETA_INTEGRAL_CONSTANT_BINARY_OP(>>)
YETA_INTEGRAL_CONSTANT_BINARY_OP(<<)
YETA_INTEGRAL_CONSTANT_BINARY_OP(>)
YETA_INTEGRAL_CONSTANT_BINARY_OP(<)
YETA_INTEGRAL_CONSTANT_BINARY_OP(<=)
YETA_INTEGRAL_CONSTANT_BINARY_OP(>=)
YETA_INTEGRAL_CONSTANT_BINARY_OP(==)
YETA_INTEGRAL_CONSTANT_BINARY_OP(!=)
YETA_INTEGRAL_CONSTANT_BINARY_OP(&)
YETA_INTEGRAL_CONSTANT_BINARY_OP(^)
YETA_INTEGRAL_CONSTANT_BINARY_OP(|)
YETA_INTEGRAL_CONSTANT_BINARY_OP(&&)
YETA_INTEGRAL_CONSTANT_BINARY_OP(||)

YETA_INTEGRAL_CONSTANT_UNARY_OP(!)
YETA_INTEGRAL_CONSTANT_UNARY_OP(~)
YETA_INTEGRAL_CONSTANT_UNARY_OP(+)
YETA_INTEGRAL_CONSTANT_UNARY_OP(-)

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

}

#endif
