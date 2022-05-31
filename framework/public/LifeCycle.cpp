#include "LifeCycle.hpp"

std::map<void *, std::vector<std::function<void()>>>
    LifeCycle::updateCallbacks = {};

std::vector<std::function<void()>> LifeCycle::everyUpdateCallbacks = {};
std::vector<std::function<void()>> LifeCycle::destroyCallbacks = {};

void LifeCycle::onEveryUpdate(const std::function<void()> &callback) {
    everyUpdateCallbacks.push_back(callback);
}

void LifeCycle::clearUpdate() {
    updateCallbacks.clear();
}

void LifeCycle::onDestroy(const std::function<void()> &callback) {
    destroyCallbacks.push_back(callback);
}

void LifeCycle::notifyDestroy() {
    for (const auto &callback : destroyCallbacks) {
        callback();
    }
}

void LifeCycle::clearDestroy() {
    destroyCallbacks.clear();
}
