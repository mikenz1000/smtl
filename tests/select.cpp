#include <smtl/select.h>
#include <smtl/math.h>
#include <type_traits>

using namespace smtl;

static_assert(std::is_same<
        vector<2,4,6>,
        select<vector<1,2,3>, multiply<int, 2>>::value
        >::value);