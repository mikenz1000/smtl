#include "smtl/where.h"

using namespace smtl;

static_assert(std::is_same<vector<1,2>, where<vector<1,2,3>, lt<3> >::value >::value);
static_assert(std::is_same<vector<3,4>, where<vector<1,2,3,4>, gte<3> >::value >::value);