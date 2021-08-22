#include <assert.h>
#include <smtl/contains.h>

using namespace std;
using namespace smtl;

static_assert(is_same< contains<int, 2, vector<int, 1,2,3>>::value , std::true_type  >::value);
static_assert(is_same< contains<int, 4, vector<int, 1,2,3>>::value , std::false_type >::value);
