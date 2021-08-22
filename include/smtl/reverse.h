#ifndef SMTL_REVERSE_H
#define SMTL_REVERSE_H
#include "vector.h"

namespace smtl {

template<typename T, typename Input, typename Output = vector<T>>
struct reverse{};

template<typename T, T first, T... input, T...output>
struct reverse<T, vector<T, first, input...>, vector<T, output...>> {
    using value = typename reverse<T, vector<T, input...>, vector<T, first, output...>>::value;
};

template<typename T, T...output>
struct reverse<T, vector<T>, vector<T, output...>> {
    using value = vector<T, output...>;
};

}

#endif //SMTL_REVERSE_H
