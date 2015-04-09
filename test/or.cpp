
#include "test.h"
#include <yeta/integral_constant.h>
#include <yeta/or.h>
#include <yeta/always.h>
#include <yeta/apply.h>

PROVE_STATIC_CASE()
{
    static_assert(yeta::or_c<true, true>::type(), "Failed");
    static_assert(yeta::or_c<true, false>::type(), "Failed");
    static_assert(yeta::or_c<true, true, true>::type(), "Failed");
    static_assert(yeta::or_c<true, false, true>::type(), "Failed");
    
    static_assert(!yeta::or_c<false, false>::type(), "Failed");
    static_assert(!yeta::or_c<false, false, false>::type(), "Failed");

    static_assert(yeta::or_<yeta::true_type, yeta::true_type>::type(), "Failed");
    static_assert(yeta::or_<yeta::true_type, yeta::false_type>::type(), "Failed");
    static_assert(yeta::or_<yeta::true_type, yeta::true_type, yeta::true_type>::type(), "Failed");
    static_assert(yeta::or_<yeta::true_type, yeta::false_type, yeta::true_type>::type(), "Failed");
    
    static_assert(!yeta::or_<yeta::false_type, yeta::false_type>::type(), "Failed");
    static_assert(!yeta::or_<yeta::false_type, yeta::false_type, yeta::false_type>::type(), "Failed");

    typedef yeta::always<yeta::true_type> always_true;
    typedef yeta::always<yeta::false_type> always_false;

    static_assert(yeta::or_<yeta::apply<always_true, int>, yeta::apply<always_true, int>>::type(), "Failed");
    static_assert(yeta::or_<yeta::apply<always_true, int>, yeta::apply<always_false, int>>::type(), "Failed");
    static_assert(yeta::or_<yeta::apply<always_true, int>, yeta::apply<always_true, int>, yeta::apply<always_true, int>>::type(), "Failed");
    static_assert(yeta::or_<yeta::apply<always_true, int>, yeta::apply<always_false, int>, yeta::apply<always_true, int>>::type(), "Failed");
    
    static_assert(!yeta::or_<yeta::apply<always_false, int>, yeta::apply<always_false, int>>::type(), "Failed");
    static_assert(!yeta::or_<yeta::apply<always_false, int>, yeta::apply<always_false, int>, yeta::false_type>::type(), "Failed");
};