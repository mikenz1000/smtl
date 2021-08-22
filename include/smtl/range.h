#ifndef SMTL_RANGE_H
#define SMTL_RANGE_H

#include "vector.h"

namespace smtl {

template<auto start, auto end, typename Output=vector<>>
        struct range;

template<auto start, auto end, auto... output>
struct range<start, end, vector<output...>> {
    using value = typename range<start+1, end, vector<output..., start> >::value;
};

// terminator, when we have reached the end
template<auto end, auto... output>
struct range<end, end, vector<output...>> {
    using value = vector<output...>;
};

}


#endif //SMTL_RANGE_H
