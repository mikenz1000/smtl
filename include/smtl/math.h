#ifndef SMTL_MATH_H
#define SMTL_MATH_H

template<int factor>
struct multiply {
    template<int target>
    struct apply {
        static const int value = factor * target;
    };
};

#endif //SMTL_MATH_H
