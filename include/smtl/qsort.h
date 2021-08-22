#ifndef SMTL_QSORT_H
#define SMTL_QSORT_H

#include "vector.h"
#include "where.h"
#include "concat.h"

namespace smtl {

template<typename T>
struct qsort;

// terminator for empty vector
template<>
struct qsort<vector<>> {
    using value = vector<>;
};

// terminator for single-element vector
template<typename T, T first>
struct qsort<vector<first>> {
    using value = vector<first>;
};

// general case - choose first element as pivot, split and reassemble as:
// sorted-left ... pivot ... sorted-right
template<typename T, T first, T... a>
struct qsort<vector<first, a...>> {

    using value = typename concat<
            typename qsort<typename where<vector<a...>, lt<T, first>>::value>::value,
            vector<first>,
            typename qsort<typename where<vector<a...>, gte<T, first>>::value>::value
            >::value;

};

}

#endif //SMTL_QSORT_H
