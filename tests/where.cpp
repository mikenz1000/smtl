#include <smtl/where.h>

using namespace smtl;

static_assert(std::is_same<vector<int, 1,2>, where<vector<int, 1,2,3>, lt<int, 3> >::value >::value);
static_assert(std::is_same<vector<int, 3,4>, where<vector<int, 1,2,3,4>, gte<int, 3> >::value >::value);
static_assert(std::is_same<vector<char, 3,4>, where<vector<char, 1,2,3,4>, gte<char, 3> >::value >::value);