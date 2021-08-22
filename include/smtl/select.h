#ifndef SMTL_SELECT_H
#define SMTL_SELECT_H

#include "vector.h"

namespace smtl {


template<typename Input, typename op, typename Output=vector<>>
struct select;

template<typename T, T first, T... rest, typename op, T... output>
struct select<vector<first, rest...>, op, vector<output...>>
{
    using value = typename select<vector<rest...>,
            op, vector<output...,
                        op::template apply<first>::value
                        >
            >::value;
};


// terminator
template<typename T, typename op, T... output>
struct select<vector<>, op, vector<output...>>
{
    using value = vector<output...>;
};

}
#endif //SMTL_SELECT_H
