# Standard Meta-Template Library

This project is an experiment in implementing STL and LINQ concepts using
template metaprogramming.  The tests folder contains cpp files that show all the templates being used. Selected
highlights are...

## Vector

[vector.h](include/smtl/vector.h) defines a simple templated vector where the variadic template arguments are
the elements of the vector
```c++
#include "smtl/vector.h"
using smtl;
vector<1,2,3> v;
```

## Template metaprogramming QSort

See [qsort.h](include/smtl/qsort.h) for a template that will sort a templated vector using
the qsort algorithm
```c++
#include "smtl/qsort.h"
using smtl;
static_assert(std::is_same<::smtl::qsort<vector<3,2,1>>::value, 
                           vector<1,2,3>>::value
                           )
```

### Reverse a vector template list

See [reverse.h](include/smtl/reverse.h) for a template that will reverse the arguments of
a templated vector.
```c++
#include "smtl/reverse.h"
using smtl;
static_assert(std::is_same<vector<1,2,3>,reverse<vector<3,2,1>>::value>::value);
```
