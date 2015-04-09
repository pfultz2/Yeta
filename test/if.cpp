

#include "test.h"
#include <yeta/if.h>
#include <yeta/bool.h>
#include <yeta/always.h>
#include <yeta/apply.h>

PROVE_STATIC_CASE()
{
    STATIC_ASSERT_SAME(typename yeta::if_c<true, int, float>::type, int);
    STATIC_ASSERT_SAME(typename yeta::if_c<false, int, float>::type, float);
};

PROVE_STATIC_CASE()
{
    STATIC_ASSERT_SAME(typename 
        yeta::if_c<true, int>
        ::template else_<float>
    ::type, int);

    STATIC_ASSERT_SAME(typename 
        yeta::if_c<false, int>
        ::template else_<float>
    ::type, float);
};

PROVE_STATIC_CASE()
{
    STATIC_ASSERT_SAME(typename 
        yeta::if_c<true, int>
        ::template else_if_c<true, void>
        ::template else_<float>
    ::type, int);

    STATIC_ASSERT_SAME(typename 
        yeta::if_c<true, int>
        ::template else_if_c<false, void>
        ::template else_<float>
    ::type, int);

    STATIC_ASSERT_SAME(typename 
        yeta::if_c<false, int>
        ::template else_if_c<true, void>
        ::template else_<float>
    ::type, void);

    STATIC_ASSERT_SAME(typename 
        yeta::if_c<false, int>
        ::template else_if_c<false, void>
        ::template else_<float>
    ::type, float);
};

PROVE_STATIC_CASE()
{
    STATIC_ASSERT_SAME(typename yeta::if_<yeta::true_type, int, float>::type, int);
    STATIC_ASSERT_SAME(typename yeta::if_<yeta::false_type, int, float>::type, float);
};

PROVE_STATIC_CASE()
{
    STATIC_ASSERT_SAME(typename 
        yeta::if_<yeta::true_type, int>
        ::template else_<float>
    ::type, int);

    STATIC_ASSERT_SAME(typename 
        yeta::if_<yeta::false_type, int>
        ::template else_<float>
    ::type, float);
};

PROVE_STATIC_CASE()
{
    STATIC_ASSERT_SAME(typename 
        yeta::if_<yeta::true_type, int>
        ::template else_if<yeta::true_type, void>
        ::template else_<float>
    ::type, int);

    STATIC_ASSERT_SAME(typename 
        yeta::if_<yeta::true_type, int>
        ::template else_if<yeta::false_type, void>
        ::template else_<float>
    ::type, int);

    STATIC_ASSERT_SAME(typename 
        yeta::if_<yeta::false_type, int>
        ::template else_if<yeta::true_type, void>
        ::template else_<float>
    ::type, void);

    STATIC_ASSERT_SAME(typename 
        yeta::if_<yeta::false_type, int>
        ::template else_if<yeta::false_type, void>
        ::template else_<float>
    ::type, float);
};


template<class... Ts>
struct always_true
: yeta::apply<yeta::always<yeta::true_type>, Ts...>
{};

template<class... Ts>
struct always_false
: yeta::apply<yeta::always<yeta::false_type>, Ts...>
{};

PROVE_STATIC_CASE()
{
    STATIC_ASSERT_SAME(typename yeta::if_<always_true<int>, int, float>::type, int);
    STATIC_ASSERT_SAME(typename yeta::if_<always_false<int>, int, float>::type, float);
};

PROVE_STATIC_CASE()
{
    STATIC_ASSERT_SAME(typename 
        yeta::if_<always_true<int>, int>
        ::template else_<float>
    ::type, int);

    STATIC_ASSERT_SAME(typename 
        yeta::if_<always_false<int>, int>
        ::template else_<float>
    ::type, float);
};

PROVE_STATIC_CASE()
{
    STATIC_ASSERT_SAME(typename 
        yeta::if_<always_true<int>, int>
        ::template else_if<always_true<int>, void>
        ::template else_<float>
    ::type, int);

    STATIC_ASSERT_SAME(typename 
        yeta::if_<always_true<int>, int>
        ::template else_if<always_false<int>, void>
        ::template else_<float>
    ::type, int);

    STATIC_ASSERT_SAME(typename 
        yeta::if_<always_false<int>, int>
        ::template else_if<always_true<int>, void>
        ::template else_<float>
    ::type, void);

    STATIC_ASSERT_SAME(typename 
        yeta::if_<always_false<int>, int>
        ::template else_if<yeta::false_type, void>
        ::template else_<float>
    ::type, float);
};

