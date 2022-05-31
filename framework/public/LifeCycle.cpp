#include "LifeCycle.hpp"

std::map<void *, std::vector<std::function<void()>>>
    LifeCycle::updateCallbacks = {};

std::vector<std::function<void()>> LifeCycle::everyUpdateCallbacks = {};

void LifeCycle::onEveryUpdate(const std::function<void()> &callback) {
    everyUpdateCallbacks.push_back(callback);
}

void LifeCycle::clearUpdate() {
    updateCallbacks.clear();
}