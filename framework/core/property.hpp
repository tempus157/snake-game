#ifndef __FRAMEWORK_PROPERTY__
#define __FRAMEWORK_PROPERTY__

#include "state.hpp"

// TODO delete value; somewhere
// or make it unique_ptr
template <typename T>
class Property {
public:
    Property<T>() : value(new T()) {}
    Property<T>(const T &value) : value(new T(value)) {}
    Property<std::string>(const char *value) : value(new std::string(value)) {}
    Property<T>(const State<T> &value) : value(value.operator->()) {}

    T operator*() const {
        return *value;
    }

    T *operator->() const {
        return value;
    }

    Property<T> &operator=(const T &value) {
        *this->value = value;
        return *this;
    }

    Property<std::string> &operator=(const char *value) {
        *this->value = value;
        return *this;
    }

private:
    T *value;
};

#endif