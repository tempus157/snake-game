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
    static std::function<void()> updateWindows;

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
        notifyUpdate(before, *this->value);
        return *this;
    }

    State<std::string> &operator=(const char *value) {
        const auto before = *this->value;
        *this->value = value;
        notifyUpdate(before, *this->value);
        return *this;
    }

    void onUpdate(const std::function<void(const T &, T &)> &callback) {
        updateCallbacks.push_back(callback);
    }

private:
    T *value;
    std::vector<std::function<void(const T &, T &)>> updateCallbacks;

    void notifyUpdate(const T &before, T &after) {
        for (const auto &callback : updateCallbacks) {
            callback(before, after);
        }

        App::update();
    }
};

#endif