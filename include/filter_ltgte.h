#ifndef SMTL_SPLIT_H
#define SMTL_SPLIT_H
#include "vector.h"
#include <type_traits>

namespace smtl {

template<int pred, typename T, typename Output=vector<> >
struct LT;

template<int pred, int first, int... rest, int... output>
struct LT<pred, vector<first, rest...>, vector<output...> > {
    using value = typename std::conditional<
            first < pred,
            typename LT<pred, vector<rest...>, vector<output..., first> >::value,
            typename LT<pred, vector<rest...>, vector<output...> >::value
            >::type;
};
template<int pred, int... output>
struct LT<pred, vector<>, vector<output...> > {
    using value = vector<output...>;
};


template<int pred, typename T, typename Output=vector<> >
        struct GTE;
template<int pred, int first, int... rest, int... output>
struct GTE<pred, vector<first, rest...>, vector<output...> > {
    using value = typename std::conditional<
            first >= pred,
            typename GTE<pred, vector<rest...>, vector<output..., first> >::value,
            typename GTE<pred, vector<rest...>, vector<output...> >::value
            >::type;
};
template<int pred, int... output>
struct GTE<pred, vector<>, vector<output...> > {
    using value = vector<output...>;
};

}

#endif
