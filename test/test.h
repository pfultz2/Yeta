
#include "prove.h"
#include <type_traits>

#define STATIC_ASSERT_SAME(...) static_assert(std::is_same<__VA_ARGS__>::value, #__VA_ARGS__)

int main()
{
    prove::run();
}
