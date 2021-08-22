#include "filter_ltgte.h"

using namespace smtl;

static_assert(std::is_same<vector<1>, LT<2,vector<1,2,3>>::value>::value);
static_assert(std::is_same<vector<2,3>, GTE<2,vector<1,2,3>>::value>::value);

static_assert(std::is_same<vector<>, LT<1,vector<1,2,3>>::value>::value);
static_assert(std::is_same<vector<1,2,3>, GTE<1,vector<1,2,3>>::value>::value);
