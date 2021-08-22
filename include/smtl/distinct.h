#ifndef SMTL_UNIQUE_H
#define SMTL_UNIQUE_H

#include "vector.h"

namespace smtl {

template<typename input, typename output=vector<> >
        struct distinct;

// template to remove first if a duplicate
template<int first, int... remaining, int... output>
struct distinct<vector<first, first, remaining...>, vector<output...>> {
    using value = typename distinct<vector<remaining...>, vector<output..., first>>::value;
};

// stopping condition
template<int... output>
struct distinct<vector<>, vector<output...>> {
    using value = vector<output...>;
};

// template to recurse normally
template<int first, int... remaining, int... output>
struct distinct<vector<first, remaining...>, vector<output...>> {
    using value = typename distinct<vector<remaining...>, vector<output..., first>>::value;
};

}

#endif //SMTL_UNIQUE_H

