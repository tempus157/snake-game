#ifndef __FRAMEWORK_UTILS_OPTIONAL__
#define __FRAMEWORK_UTILS_OPTIONAL__

#include <__nullptr>

template <typename T>
struct Optional
{
public:
    T value;
    bool hasValue;

    Optional() : hasValue(false) {}
    Optional(const std::nullptr_t &value) : Optional() {}
    Optional(const T &value) : value(value), hasValue(true) {}

    Optional<T> &operator=(const std::nullptr_t &value)
    {
        hasValue = false;
        return *this;
    }

    Optional<T> &operator=(const T &value)
    {
        this->value = value;
        this->hasValue = true;
        return *this;
    }
};

#endif
