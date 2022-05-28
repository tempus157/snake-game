#ifndef __FRAMEWORK_STATE__
#define __FRAMEWORK_STATE__

#include "app.hpp"

#include <functional>
#include <map>
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
        *this->value = value;
        notifyUpdate();
        return *this;
    }

    State<std::string> &operator=(const char *value) {
        *this->value = value;
        notifyUpdate();
        return *this;
    }

    static void onUpdate(const State<T> state,
                         const std::function<void()> &callback) {
        updateCallbacks[state.value].push_back(callback);
    }

private:
    T *value;
    static std::map<T *, std::vector<std::function<void()>>> updateCallbacks;

    void notifyUpdate() {
        for (const auto &callback : updateCallbacks[value]) {
            callback();
        }
        App::update();
    }
};

template <typename T>
std::map<T *, std::vector<std::function<void()>>>
    State<T>::updateCallbacks = {};

#endif