#include <assert.h>
#include <smtl/distinct.h>

using namespace smtl;

static_assert(std::is_same<vector<int, 1,2,3>, distinct<int, vector<int, 1,1,2,3>>::value>::value);
