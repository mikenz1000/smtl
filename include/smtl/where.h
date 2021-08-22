#ifndef SMTL_WHERE_H
#define SMTL_WHERE_H

#include <type_traits>
#include "vector.h"

namespace smtl {

/*
 * filters a vector T using predicate pred
 */
template<typename Input, typename Pred, typename Output=typename Input::empty_type>
struct where;

template<typename T, T first, T... i, T... o, typename pred>
struct where<vector<T, first, i...>, pred, vector<T, o...>> {
    using value = typename std::conditional<pred::template eval<first>::result,
        // if true, include first in output
        typename where<vector<T, i...>, pred, vector<T, o..., first>>::value,
        // if false, skip
        typename where<vector<T, i...>, pred, vector<T, o...>>::value
        >::type;
};

// terminator
template<typename T, T... o, typename pred>
struct where<vector<T>, pred, vector<T, o...>> {
    using value = vector<T, o...>;
};

// less than comparison predicate
template<typename T, T x>
struct lt {
    template<T i>
    struct eval {
        static const bool result = i < x;
    };
};

// greater than or equal comparison predicate
template<typename T, T x>
struct gte {
    template<T i>
    struct eval {
        static const bool result = i >= x;
    };
};

}

#endif //SMTL_WHERE_H
