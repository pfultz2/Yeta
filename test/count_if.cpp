
#include "test.h"
#include <yeta/count_if.h>
#include <yeta/apply.h>
#include <yeta/quote.h>
#include <yeta/list.h>
#include <yeta/int.h>

using yeta::int_;

template<class T>
struct predicate
: decltype(std::declval<typename T::type>() > int_<1>())
{};


PROVE_STATIC_CASE()
{
    typedef yeta::quote<predicate> predicate_class;

    typedef yeta::list<int_<0>, int_<1>, int_<2>, int_<0>, int_<3>, int_<4>, int_<0>, int_<-1>> ints;

    static_assert(yeta::count_if<ints, predicate_class>::type() == 3, "");
};
