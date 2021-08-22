#include <assert.h>
#include <smtl/concat.h>

using namespace smtl;
using namespace std;

static_assert(is_same< concat<vector<1,2>, vector<3,4>>::value , vector<1,2,3,4> >::value);
static_assert(is_same< concat<vector<1>, vector<2,3,4>>::value , vector<1,2,3,4> >::value);
static_assert(is_same< concat<vector<1,2,3>, vector<4>>::value , vector<1,2,3,4> >::value);
static_assert(is_same< concat<vector<>, vector<1,2,3,4>>::value , vector<1,2,3,4> >::value);
static_assert(is_same< concat<vector<1,2,3,4>, vector<>>::value , vector<1,2,3,4> >::value);
