#ifndef SMTL_REVERSE_H
#define SMTL_REVERSE_H

namespace smtl {

template<int... I>
struct vector {};

template<typename Input, typename Output = vector<>>
        struct reverse{};

template<int first, int... input, int...output>
struct reverse<vector<first, input...>, vector<output...>> {
    using value = typename reverse<vector<input...>, vector<first, output...>>::value;
};

template<int...output>
struct reverse<vector<>, vector<output...>> {
    using value = vector<output...>;
};

}

#endif //SMTL_REVERSE_H
