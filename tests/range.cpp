#include <smtl/range.h>
#include <type_traits>

using namespace smtl;

static_assert(std::is_same<range<1,4>::value, vector<1,2,3>>::value);