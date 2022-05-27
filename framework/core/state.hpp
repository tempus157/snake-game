#ifndef __FRAMEWORK_STATE__
#define __FRAMEWORK_STATE__

#include "app.hpp"
#include <unistd.h>

// TODO delete value; somewhere
template <typename T>
class State {
public:
    State<T>() : value(new T()) {}
    State<T>(const T &value) : value(new T(value)) {}
    State<std::string>(const char *value) : value(new std::string(value)) {}

    T *operator->() const {
        return value;
    }

    State<T> &operator=(const T &value) {
        *this->value = value;
        App::instance->updateWindows();
        return *this;
    }

private:
    T *value;
};

#endif