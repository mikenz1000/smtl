#include <smtl/math.h>
#include <type_traits>

using namespace smtl;

static_assert(std::is_same<multiply<2>::apply<3>::value, 6);
