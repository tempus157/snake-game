#ifndef __FRAMEWORK_PROPERTY__
#define __FRAMEWORK_PROPERTY__

#include "app.hpp"
#include <unistd.h>

// TODO delete value; somewhere
template <typename T>
class Property {
public:
    Property<T>() : value(new T()) {}
    Property<T>(const T &value) : value(new T(value)) {}
    Property<std::string>(const char *value) : value(new std::string(value)) {}

    T &operator*() const {
        return *value;
    }

    T *operator->() const {
        return value;
    }

    Property<T> &operator=(const T &value) {
        *this->value = value;
        App::instance->updateWindows();
        return *this;
    }

    Property<std::string> &operator=(const char *value) {
        *this->value = value;
        App::instance->updateWindows();
        return *this;
    }

private:
    T *value;
};

#endif