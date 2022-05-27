#ifndef __FRAMEWORK_OPTIONAL__
#define __FRAMEWORK_OPTIONAL__

#include <__nullptr>

template <typename T>
class Optional {
public:
    T value;
    bool hasValue;

    Optional() : hasValue(false) {}
    Optional(const std::nullptr_t &value) : Optional() {}
    Optional(const T &value) : value(value), hasValue(true) {}

    operator bool() const {
        return hasValue;
    }

    operator T() const {
        if (!hasValue) {
            throw std::runtime_error("Optional does not have a value");
        }

        return value;
    }

    const T *operator->() const {
        if (!hasValue) {
            throw std::runtime_error("Optional does not have a value");
        }

        return &value;
    }

    Optional<T> &operator=(const std::nullptr_t &value) {
        hasValue = false;
        return *this;
    }

    Optional<T> &operator=(const T &value) {
        this->value = value;
        this->hasValue = true;
        return *this;
    }
};

#endif