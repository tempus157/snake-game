#ifndef __FRAMEWORK_STATE__
#define __FRAMEWORK_STATE__

#include "app.hpp"
#include <unistd.h>

// TODO delete value; somewhere
template <typename T>
class Property {
public:
    Property<T>() : value(new T()) {}
    Property<T>(const T &value) : value(new T(value)) {}
    Property<std::string>(const char *value) : value(new std::string(value)) {}

    T *operator->() const {
        return value;
    }

    Property<T> &operator=(const T &value) {
        *this->value = value;
        App::instance->updateWindows();
        return *this;
    }

private:
    T *value;
};

#endif