#ifndef __FRAMEWORK_STATE__
#define __FRAMEWORK_STATE__

#include "app.hpp"
#include <unistd.h>

template <typename T>
class State {
public:
    State() : value(new T()) {}
    State(const T &value) : value(new T(value)) {}

    T &get() const {
        return *value;
    }

    void set(const T &value) {
        *(this->value) = value;
        App::instance->updateWindows();
    }

private:
    T *value;
};

#endif