#include "test.h"
#include <yeta/list.h>
#include <yeta/id.h>
#include <yeta/clear.h>
#include <yeta/empty.h>
#include <yeta/front.h>
#include <yeta/push_front.h>
#include <yeta/push_back.h>
#include <yeta/apply.h>
#include <yeta/int.h>

using yeta::list;
using yeta::id;

PROVE_STATIC_CASE()
{
    STATIC_ASSERT_SAME(typename yeta::push_back<list<>, id<int>>::type, list<int>);
    STATIC_ASSERT_SAME(typename yeta::push_front<list<>, id<int>>::type, list<int>);
    static_assert(yeta::empty<list<>>(), "Failed");
    static_assert(!yeta::empty<list<int>>(), "Failed");

    STATIC_ASSERT_SAME(typename yeta::push_back<list<long>, id<int>>::type, list<long, int>);
    STATIC_ASSERT_SAME(typename yeta::push_front<list<long>, id<int>>::type, list<int, long>);

    STATIC_ASSERT_SAME(typename yeta::front<list<long, int>>::type, long);
    STATIC_ASSERT_SAME(typename yeta::clear<list<long, int>>::type, list<>);
};