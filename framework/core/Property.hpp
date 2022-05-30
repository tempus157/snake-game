#ifndef __FRAMEWORK_PROPERTY__
#define __FRAMEWORK_PROPERTY__

#include "App.hpp"
#include "PropertyEvent.hpp"

#include <functional>
#include <map>
#include <memory>
#include <vector>

template <typename T>
class Property final {
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
        PropertyEvent::notifyUpdate(this->value.get());
        return *this;
    }

private:
    std::shared_ptr<T> value;
};

#endif