#ifndef __FRAMEWORK_PROPERTY__
#define __FRAMEWORK_PROPERTY__

#include "App.hpp"
#include "LifeCycle.hpp"

#include <functional>
#include <initializer_list>
#include <map>
#include <memory>
#include <vector>

template <typename T>
class Property final {
public:
    Property<T>() : value(std::make_shared<T>()) {}
    Property<T>(const T &value) : value(std::make_shared<T>(value)) {}

    template <typename T2>
    Property<T>(const std::initializer_list<T2> &list)
        : value(std::make_shared<T>(list)) {}

    Property<std::string>(const char *value)
        : value(std::make_shared<std::string>(value)) {}

    T operator*() const {
        return *value;
    }

    T *operator->() const {
        return value.get();
    }

    Property<T> &operator=(const T &value) = delete;
    Property<std::string> &operator=(const char *value) = delete;

    void set(const T &value) {
        *this->value = value;
        LifeCycle::notifyUpdate(this->value.get());
    }

private:
    std::shared_ptr<T> value;
};

#endif