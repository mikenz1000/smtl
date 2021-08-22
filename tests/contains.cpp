#include <assert.h>
#include <smtl/contains.h>

using namespace std;
using namespace smtl;

static_assert(is_same< contains<2, vector<1,2,3>>::value , std::true_type  >::value);
static_assert(is_same< contains<4, vector<1,2,3>>::value , std::false_type >::value);
