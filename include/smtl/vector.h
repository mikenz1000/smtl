#ifndef SMTL_VECTOR_H
#define SMTL_VECTOR_H

namespace smtl {

template<typename T, T... i>

struct vector {
    // equivalent vector with no elements - used to allow referring code to determine empty_type without knowing T
    using empty_type = vector<T>;
};

}

#endif
