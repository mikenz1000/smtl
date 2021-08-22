#ifndef SMTL_UNIQUE_H
#define SMTL_UNIQUE_H

#include "vector.h"

namespace smtl {

template<typename T, typename input, typename output=vector<T> >
        struct distinct;

// template to remove first if a duplicate
template<typename T, T first, T... remaining, T... output>
struct distinct<T, vector<T, first, first, remaining...>, vector<T, output...>> {
    using value = typename distinct<T, vector<T, remaining...>, vector<T, output..., first>>::value;
};

// stopping condition
template<typename T, T... output>
struct distinct<T, vector<T>, vector<T,output...>> {
    using value = vector<T, output...>;
};

// template to recurse normally
template<typename T, T first, T... remaining, T... output>
struct distinct<T, vector<T, first, remaining...>, vector<T, output...>> {
    using value = typename distinct<T, vector<T, remaining...>, vector<T, output..., first>>::value;
};

}

#endif //SMTL_UNIQUE_H

