#ifndef SMTL_WHERE_H
#define SMTL_WHERE_H

#include <type_traits>
#include "vector.h"

namespace smtl {

/*
 * filters a vector T using predicate pred
 */
template<typename T, typename pred, typename Output=vector<>>
struct where;

template<int first, int... i, int... o, typename pred>
struct where<vector<first, i...>, pred, vector<o...>> {
    using value = typename std::conditional<pred::template eval<first>::result,
        // if true, include first in output
        typename where<vector<i...>, pred, vector<o..., first>>::value,
        // if false, skip
        typename where<vector<i...>, pred, vector<o...>>::value
        >::type;
};

// terminator
template<int... o, typename pred>
struct where<vector<>, pred, vector<o...>> {
    using value = vector<o...>;
};

// less than comparison predicate
template<int x>
struct lt {
    template<int i>
    struct eval {
        static const bool result = i < x;
    };
};

// greater than or equal comparison predicate
template<int x>
struct gte {
    template<int i>
    struct eval {
        static const bool result = i >= x;
    };
};

}

#endif //SMTL_WHERE_H
