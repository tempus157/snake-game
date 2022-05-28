#ifndef __FRAMEWORK_STATE__
#define __FRAMEWORK_STATE__

#include "app.hpp"
#include <functional>
#include <vector>

// TODO delete value; somewhere
// or make it unique_ptr
template <typename T>
class State {
public:
    State<T>() : value(new T()) {}
    State<T>(const T &value) : value(new T(value)) {}
    State<std::string>(const char *value) : value(new std::string(value)) {}

    T operator*() const {
        return *value;
    }

    T *operator->() const {
        return value;
    }

    State<T> &operator=(const T &value) {
        const auto before = *this->value;
        *this->value = value;
        notifyChange(before, *this->value);
        return *this;
    }

    State<std::string> &operator=(const char *value) {
        const auto before = *this->value;
        *this->value = value;
        notifyChange(before, *this->value);
        return *this;
    }

    void onChange(const std::function<void(const T &, const T &)> &fn) {
        change.push_back(fn);
    }

private:
    T *value;
    std::vector<std::function<void(const T &, const T &)>> change;

    void notifyChange(const T &before, const T &after) {
        for (const auto &fn : change) {
            fn(before, after);
        }

        App::instance->update();
    }
};

#endif