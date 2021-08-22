#ifndef SMTL_UNIQUE_H
#define SMTL_UNIQUE_H

#include "vector.h"

namespace smtl {

template<typename Input, typename output=typename Input::empty_type >
        struct distinct;

// template to remove first if a duplicate
template<typename T, T first, T... remaining, T... output>
struct distinct<vector<T, first, first, remaining...>, vector<T, output...>> {
    using value = typename distinct<vector<T, remaining...>, vector<T, output..., first>>::value;
};

// stopping condition
template<typename T, T... output>
struct distinct<vector<T>, vector<T,output...>> {
    using value = vector<T, output...>;
};

// template to recurse normally
template<typename T, T first, T... remaining, T... output>
struct distinct<vector<T, first, remaining...>, vector<T, output...>> {
    using value = typename distinct<vector<T, remaining...>, vector<T, output..., first>>::value;
};

}

#endif //SMTL_UNIQUE_H

