#ifndef SMTL_CONTAINS_H
#define SMTL_CONTAINS_H

#include "vector.h"

namespace smtl {

template<int sought, typename Input>
struct contains{};

// match when sought at beginning of list
template<int sought, int... rest>
struct contains<sought, vector<sought, rest...>> {
    using value = std::true_type;
};

// move through list otherwise
template<int sought, int first, int... rest>
struct contains<sought, vector<first, rest...>> {
    using value = typename contains<sought, vector<rest...>>::value;
};

// terminator
template<int sought>
struct contains<sought, vector<>> {
    using value = std::false_type;
};

}

#endif //SMTL_CONTAINS_H
