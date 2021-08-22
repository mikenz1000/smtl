#ifndef SMTL_CONCAT_H
#define SMTL_CONCAT_H
#include "vector.h"

namespace smtl {

template<typename A, typename B>
struct concat{};

// match when sought at beginning of list
template<int... allA, int firstB, int... restB>
struct concat<vector<allA...>, vector<firstB, restB...>> {
    using value = typename concat<vector<allA..., firstB>, vector<restB...>>::value;
};

// terminator
template<int... allA>
struct concat<vector<allA...>, vector<>> {
    using value = vector<allA...>;
};

}
#endif
