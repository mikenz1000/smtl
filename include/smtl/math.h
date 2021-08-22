#ifndef SMTL_MATH_H
#define SMTL_MATH_H

namespace smtl {

template<auto factor>
struct multiply {
    template<auto target>
    struct apply {
        static const decltype(target) value = factor * target;
    };
};

}

#endif //SMTL_MATH_H
