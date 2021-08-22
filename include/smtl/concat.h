#ifndef SMTL_CONCAT_H
#define SMTL_CONCAT_H
#include "vector.h"

namespace smtl {

template<typename A, typename B>
struct concat{};

// match when sought at beginning of list
template<typename T, T... allA, T firstB, T... restB>
struct concat<vector<T, allA...>, vector<T, firstB, restB...>> {
    using value = typename concat<vector<T, allA..., firstB>, vector<T, restB...>>::value;
};

// terminator
template<typename T, T... allA>
struct concat<vector<T, allA...>, vector<T>> {
    using value = vector<T, allA...>;
};

}
#endif
