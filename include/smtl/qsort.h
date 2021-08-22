#ifndef SMTL_QSORT_H
#define SMTL_QSORT_H

#include "vector.h"
#include "where.h"
#include "concat.h"

namespace smtl {

template<typename T>
struct qsort;

// terminator
template<typename T>
struct qsort<vector<T>> {
    using value = vector<T>;
};

// template to use during computation
template<typename T, T first>
struct qsort<vector<T, first>> {
    using value = vector<T, first>;
};


// template to use during computation
template<typename T, T first, T... a>
struct qsort<vector<T, first, a...>> {

    //    using split = Split< first, vector<first, a...> >;

    using value = typename concat<
            typename concat<
            typename qsort<typename where<vector<T, a...>, lt<T, first>>::value>::value,
            vector<T, first>
            >::value,
            typename qsort<typename where<vector<T, a...>, gte<T, first>>::value>::value
            >::value;

};

}

#endif //SMTL_QSORT_H
