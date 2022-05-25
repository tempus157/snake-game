#ifndef __FRAMEWORK_UTILS_OPTIONAL__
#define __FRAMEWORK_UTILS_OPTIONAL__

#include <__nullptr>

template <typename T>
class Optional
{
public:
    T value;
    bool hasValue;

    Optional() : hasValue(false) {}
    Optional(std::nullptr_t const &value) : Optional() {}
    Optional(T const &value) : value(value), hasValue(true) {}

    Optional<T> &operator=(std::nullptr_t const &value)
    {
        hasValue = false;
        return *this;
    }

    Optional<T> &operator=(T const &value)
    {
        this->value = value;
        this->hasValue = true;
        return *this;
    }
};

#endif
