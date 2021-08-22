#ifndef SMTL_REVERSE_H
#define SMTL_REVERSE_H
#include "vector.h"

namespace smtl {

template<typename Input, typename Output = vector<>>
struct reverse{};

template<typename T, T first, T... input, T...output>
struct reverse<vector<first, input...>, vector<output...>> {
    using value = typename reverse<vector<input...>, vector<first, output...>>::value;
};

template<typename T, T...output>
struct reverse<vector<>, vector<output...>> {
    using value = vector<output...>;
};

}

#endif //SMTL_REVERSE_H
