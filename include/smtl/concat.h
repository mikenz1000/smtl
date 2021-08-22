#ifndef SMTL_CONCAT_H
#define SMTL_CONCAT_H
#include "vector.h"

namespace smtl {

template<typename... V>
struct concat{};

// concat when there are two vectors
template<typename T, T... allA, T firstB, T... restB>
struct concat<vector<allA...>, vector<firstB, restB...>> {
    using value = typename concat<vector<allA..., firstB>, vector<restB...>>::value;
};


// concat when there are more than two vectors
template<typename T, T... allA, T firstB, T... restB, typename... Rest>
struct concat<vector<allA...>, vector<firstB, restB...>, Rest...> {
    using value = typename
            concat<
                    typename concat<vector<allA..., firstB>, vector<restB...>>::value,
                    Rest...
                    >::value;
};

// terminator
template<typename T, T... allA>
struct concat<vector<allA...>, vector<>> {
    using value = vector<allA...>;
};

}
#endif
