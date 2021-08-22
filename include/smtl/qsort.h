#ifndef SMTL_QSORT_H
#define SMTL_QSORT_H

#include "vector.h"
#include "where.h"
#include "concat.h"

namespace smtl {

template<typename T>
struct qsort;

// terminator
template<>
struct qsort<vector<>> {
    using value = vector<>;
};

// template to use during computation
template<typename T, T first>
struct qsort<vector<first>> {
    using value = vector<first>;
};


// template to use during computation
template<typename T, T first, T... a>
struct qsort<vector<first, a...>> {

    //    using split = Split< first, vector<first, a...> >;

    using value = typename concat<
            typename concat<
            typename qsort<typename where<vector<a...>, lt<T, first>>::value>::value,
            vector<first>
            >::value,
            typename qsort<typename where<vector<a...>, gte<T, first>>::value>::value
            >::value;

};

}

#endif //SMTL_QSORT_H
