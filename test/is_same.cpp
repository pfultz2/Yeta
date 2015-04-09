

#include "test.h"
#include <yeta/is_same.h>
#include <yeta/id.h>

PROVE_STATIC_CASE()
{
    static_assert(yeta::is_same<yeta::id<int>, yeta::id<int>>::value, "Failed");
    static_assert(!yeta::is_same<yeta::id<int>, yeta::id<float>>::value, "Failed");
};