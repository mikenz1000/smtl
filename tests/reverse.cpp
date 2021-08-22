#include <assert.h>
#include <smtl/reverse.h>

using namespace smtl;

static_assert(std::is_same<vector<1,2,3>,reverse<vector<3,2,1>>::value>::value);