

#include "test.h"
#include <yeta/quote.h>
#include <yeta/bind_back.h>
#include <yeta/bind_front.h>
#include <yeta/apply.h>
#include <yeta/int.h>

template<class T, class U>
struct sum
: decltype(std::declval<typename T::type>() + std::declval<typename U::type>())
{};

template<class T, class U>
struct sub
: decltype(std::declval<typename T::type>() - std::declval<typename U::type>())
{};

PROVE_STATIC_CASE()
{
    typedef yeta::quote<sum> sum_class;
    typedef yeta::quote<sub> sub_class;
    static_assert(yeta::apply<sum_class, yeta::int_<1>, yeta::int_<2>>::type() == 3, "Failed");
    static_assert(yeta::apply<yeta::bind_back<sum_class, yeta::int_<1>>, yeta::int_<2>>::type() == 3, "Failed");
    static_assert(yeta::apply<yeta::bind_front<sum_class, yeta::int_<1>>, yeta::int_<2>>::type() == 3, "Failed");

    static_assert(yeta::apply<sub_class, yeta::int_<5>, yeta::int_<2>>::type() == 3, "Failed");
    static_assert(yeta::apply<yeta::bind_back<sub_class, yeta::int_<2>>, yeta::int_<5>>::type() == 3, "Failed");
    static_assert(yeta::apply<yeta::bind_front<sub_class, yeta::int_<5>>, yeta::int_<2>>::type() == 3, "Failed");
};
