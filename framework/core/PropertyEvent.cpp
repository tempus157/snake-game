#include "PropertyEvent.hpp"

std::map<void *, std::vector<std::function<void()>>>
    PropertyEvent::updateCallbacks = {};

std::vector<std::function<void()>> PropertyEvent::everyUpdateCallbacks = {};
