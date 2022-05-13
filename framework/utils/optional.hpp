#ifndef __FRAMEWORK_UTILS_OPTIONAL__
#define __FRAMEWORK_UTILS_OPTIONAL__

#include <__nullptr>

template <typename T>
struct Optional
{
public:
    T value;
    bool hasValue;

    Optional();
    Optional(std::nullptr_t value);
    Optional(T value);

    Optional<T> operator=(std::nullptr_t value);
    Optional<T> operator=(T value);
};

#endif