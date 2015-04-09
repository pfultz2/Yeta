
#include "test.h"
#include <yeta/always.h>
#include <yeta/apply.h>

PROVE_STATIC_CASE()
{
    typedef yeta::always<int> always_int;
    STATIC_ASSERT_SAME(typename always_int::template apply<long>::type, int);
    STATIC_ASSERT_SAME(typename always_int::template apply<long, long>::type, int);
    STATIC_ASSERT_SAME(typename always_int::template apply<float, double>::type, int);
    STATIC_ASSERT_SAME(typename always_int::template apply<>::type, int);

    STATIC_ASSERT_SAME(typename yeta::apply<always_int, long>::type, int);
    STATIC_ASSERT_SAME(typename yeta::apply<always_int, long, long>::type, int);
    STATIC_ASSERT_SAME(typename yeta::apply<always_int, float, double>::type, int);
    STATIC_ASSERT_SAME(typename yeta::apply<always_int>::type, int);
};
