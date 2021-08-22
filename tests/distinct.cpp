#include <assert.h>
#include "distinct.h"

using namespace smtl;

static_assert(std::is_same<vector<1,2,3>, distinct<vector<1,1,2,3>>::value>::value);
