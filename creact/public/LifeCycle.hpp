#ifndef __FRAMEWORK_PROPERTY_EVENT__
#define __FRAMEWORK_PROPERTY_EVENT__

#include "App.hpp"

#include <functional>
#include <map>
#include <memory>
#include <vector>

template <typename T>
class Property;

class LifeCycle final {
public:
    template <typename T>
    static void onUpdate(const Property<T> property,
        const std::function<void()> &callback) {
        updateCallbacks[(void *)property.operator->()].push_back(callback);
    }

    template <typename T>
    static void notifyUpdate(const T *value) {
        for (const auto &callback : updateCallbacks[(void *)value]) {
            callback();
        }
        for (const auto &callback : everyUpdateCallbacks) {
            callback();
        }
    }

    static void onEveryUpdate(const std::function<void()> &callback);
    static void clearUpdate();

private:
    static std::map<void *, std::vector<std::function<void()>>> updateCallbacks;
    static std::vector<std::function<void()>> everyUpdateCallbacks;
};

#endif