#ifndef SMTL_QSORT_H
#define SMTL_QSORT_H

#include "vector.h"
#include "filter_ltgte.h"
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
template<int first>
struct qsort<vector<first>> {
    using value = vector<first>;
};


// template to use during computation
template<int first, int... a>
struct qsort<vector<first, a...>> {

    //    using split = Split< first, vector<first, a...> >;

    using value = typename concat<
            typename concat<
            typename qsort<typename LT<first, vector<a...>>::value>::value,
            vector<first>
            >::value,
            typename qsort<typename GTE<first, vector<a...>>::value>::value
            >::value;

};

}

#endif //SMTL_QSORT_H
