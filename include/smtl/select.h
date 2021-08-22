#ifndef SMTL_SELECT_H
#define SMTL_SELECT_H

#include "vector.h"

namespace smtl {


template<typename T, typename op, typename Output=vector<>>
struct select;

template<int first, int... rest, typename op, int... output>
struct select<vector<first, rest...>, op, vector<output...>>
{
    using value = typename select<vector<rest...>,
            op, vector<output...,
                        op::template apply<first>::value
                        >
            >::value;
};


// terminator
template<typename op, int... output>
struct select<vector<>, op, vector<output...>>
{
    using value = vector<output...>;
};

}
#endif //SMTL_SELECT_H
