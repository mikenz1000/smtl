#include <smtl/qsort.h>

#include <assert.h>
#include <iostream>

using namespace smtl;

static_assert(std::is_same<::smtl::qsort<vector<2,1>>::value, vector<1,2>>::value);
static_assert(std::is_same<::smtl::qsort<vector<1,2,3,4,5,6,7,8,9>>::value, vector<1,2,3,4,5,6,7,8,9>>::value);
static_assert(std::is_same<::smtl::qsort<vector<3,2,1>>::value, vector<1,2,3>>::value);
static_assert(std::is_same<::smtl::qsort<vector<9,4,5,3,2,6,7,1,8>>::value, vector<1,2,3,4,5,6,7,8,9>>::value);
