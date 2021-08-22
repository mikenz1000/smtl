#ifndef SMTL_UNIQUE_H
#define SMTL_UNIQUE_H

#include "vector.h"

namespace smtl {

template<typename Input, typename output=vector<>>
        struct distinct;

// template to remove first if a duplicate
template<typename T, T first, T... remaining, T... output>
struct distinct<vector<first, first, remaining...>, vector<output...>> {
    using value = typename distinct<vector<remaining...>, vector<output..., first>>::value;
};

// stopping condition
template<typename T, T... output>
struct distinct<vector<>, vector<output...>> {
    using value = vector<output...>;
};

// template to recurse normally
template<typename T, T first, T... remaining, T... output>
struct distinct<vector<first, remaining...>, vector<output...>> {
    using value = typename distinct<vector<remaining...>, vector<output..., first>>::value;
};

}

#endif //SMTL_UNIQUE_H

