#include <assert.h>
#include <smtl/reverse.h>

using namespace smtl;

static_assert(std::is_same<vector<int, 1,2,3>,reverse<int, vector<int, 3,2,1>>::value>::value);