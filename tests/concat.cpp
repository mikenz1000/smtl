#include <assert.h>
#include <smtl/concat.h>

using namespace smtl;
using namespace std;

static_assert(is_same< concat<vector<int, 1,2>, vector<int, 3,4>>::value , vector<int, 1,2,3,4> >::value);
static_assert(is_same< concat<vector<int, 1>, vector<int, 2,3,4>>::value , vector<int, 1,2,3,4> >::value);
static_assert(is_same< concat<vector<int, 1,2,3>, vector<int, 4>>::value , vector<int, 1,2,3,4> >::value);
static_assert(is_same< concat<vector<int>, vector<int, 1,2,3,4>>::value , vector<int, 1,2,3,4> >::value);
static_assert(is_same< concat<vector<int, 1,2,3,4>, vector<int>>::value , vector<int, 1,2,3,4> >::value);
