#ifndef __FRAMEWORK_PROPERTY__
#define __FRAMEWORK_PROPERTY__

#include "app.hpp"

#include <functional>
#include <map>
#include <memory>
#include <vector>

template <typename T>
class Property {
public:
    Property<T>() : value(std::make_shared<T>()) {}
    Property<T>(const T &value) : value(std::make_shared<T>(value)) {}
    Property<std::string>(const char *value)
        : value(std::make_shared<std::string>(value)) {}

    T operator*() const {
        return *value;
    }

    T *operator->() const {
        return value.get();
    }

    Property<T> &operator=(const T &value) {
        *this->value = value;
        notifyUpdate();
        return *this;
    }

    Property<std::string> &operator=(const char *value) {
        *this->value = value;
        notifyUpdate();
        return *this;
    }

    static void onUpdate(const Property<T> state,
        const std::function<void()> &callback) {
        updateCallbacks[state.value.get()].push_back(callback);
    }

private:
    std::shared_ptr<T> value;
    static std::map<T *, std::vector<std::function<void()>>> updateCallbacks;

    void notifyUpdate() const {
        for (const auto &callback : updateCallbacks[value.get()]) {
            callback();
        }
        App::update();
    }
};

template <typename T>
std::map<T *, std::vector<std::function<void()>>>
    Property<T>::updateCallbacks = {};

#endif