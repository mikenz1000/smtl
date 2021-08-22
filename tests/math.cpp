#include <smtl/math.h>
#include <smtl/range.h>

#include <type_traits>

using namespace smtl;

static_assert(multiply<2>::apply<3>::value == 6);
