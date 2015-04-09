


#include "test.h"
#include <yeta/fold.h>
#include <yeta/apply.h>
#include <yeta/quote.h>
#include <yeta/list.h>
#include <yeta/int.h>

template<class T, class U>
struct sum
: decltype(std::declval<typename T::type>() + std::declval<typename U::type>())
{};

using yeta::int_;

PROVE_STATIC_CASE()
{
    typedef yeta::quote<sum> sum_class;

    static_assert(yeta::fold<yeta::list<int_<1>, int_<2>, int_<3>>, sum_class, int_<0>>::type() == 6, "");
    static_assert(yeta::fold<yeta::list<int_<1>, int_<2>, int_<3>>, sum_class>::type() == 6, "");
};

