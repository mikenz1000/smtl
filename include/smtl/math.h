#ifndef SMTL_MATH_H
#define SMTL_MATH_H

template<typename T, T factor>
struct multiply {
    template<T target>
    struct apply {
        static const T value = factor * target;
    };
};

#endif //SMTL_MATH_H
