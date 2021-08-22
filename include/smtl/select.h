#ifndef SMTL_SELECT_H
#define SMTL_SELECT_H

#include "vector.h"

namespace smtl {


template<typename T, typename Input, typename op, typename Output=vector<T>>
struct select;

template<typename T, T first, T... rest, typename op, T... output>
struct select<T, vector<T, first, rest...>, op, vector<T, output...>>
{
    using value = typename select<T, vector<T, rest...>,
            op, vector<T, output...,
                        op::template apply<first>::value
                        >
            >::value;
};


// terminator
template<typename T, typename op, T... output>
struct select<T, vector<T>, op, vector<T, output...>>
{
    using value = vector<T, output...>;
};

}
#endif //SMTL_SELECT_H
