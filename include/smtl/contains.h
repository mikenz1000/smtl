#ifndef SMTL_CONTAINS_H
#define SMTL_CONTAINS_H

#include "vector.h"

namespace smtl {

template<typename T, T sought, typename Input>
struct contains{};

// match when sought at beginning of list
template<typename T, T sought, T... rest>
struct contains<T, sought, vector<sought, rest...>> {
    using value = std::true_type;
};

// move through list otherwise
template<typename T, T sought, T first, T... rest>
struct contains<T, sought, vector<first, rest...>> {
    using value = typename contains<T, sought, vector<rest...>>::value;
};

// terminator
template<typename T, T sought>
struct contains<T, sought, vector<>> {
    using value = std::false_type;
};

}

#endif //SMTL_CONTAINS_H
