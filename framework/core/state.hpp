#ifndef __FRAMEWORK_STATE__
#define __FRAMEWORK_STATE__

#include "app.hpp"

#include <functional>
#include <map>
#include <memory>
#include <vector>

template <typename T>
class State {
public:
    State<T>() : value(std::make_shared<T>()) {}
    State<T>(const T &value) : value(std::make_shared<T>(value)) {}
    State<std::string>(const char *value)
        : value(std::make_shared<std::string>(value)) {}

    T operator*() const {
        return *value;
    }

    T *operator->() const {
        return value.get();
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
        updateCallbacks[state.value.get()].push_back(callback);
    }

private:
    std::shared_ptr<T> value;
    static std::map<T *, std::vector<std::function<void()>>> updateCallbacks;

    void notifyUpdate() {
        for (const auto &callback : updateCallbacks[value.get()]) {
            callback();
        }
        App::update();
    }
};

template <typename T>
std::map<T *, std::vector<std::function<void()>>>
    State<T>::updateCallbacks = {};

#endif