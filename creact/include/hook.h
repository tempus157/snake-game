#ifndef __CREACT_HOOK__
#define __CREACT_HOOK__

#include "app.h"

#include <functional>
#include <vector>

namespace InternalCreact {
    template <typename T>
    struct State {
        T value;
        std::function<void(const T &)> set;
    };

    std::vector<void *> states;
    int stateID;

    std::vector<void *> effects;
    int effectID;
}

namespace Creact {
    template <typename T>
    InternalCreact::State<T> useState() {
        return useState(T());
    }

    template <typename T>
    InternalCreact::State<T> useState(const T &initialValue) {
        const T state = InternalCreact::states.size() > InternalCreact::stateID
                            ? InternalCreact::states[InternalCreact::stateID]
                            : initialValue;

        const auto currentID = InternalCreact::stateID;
        InternalCreact::stateID++;

        return InternalCreact::State<T>{
            state, [=](const T &value) {
                InternalCreact::states[currentID] = value;
                InternalCreact::shouldUpdate = true;
            }};
    }

    template <typename TDep>
    void useEffect(const std::function<void()> callback,
        const InternalCreact::State<TDep> &dep) {
        auto hasChanged = true;
        if (InternalCreact::effects.size() > InternalCreact::effectID) {
            hasChanged = InternalCreact::effects[InternalCreact::effectID] != dep.value;
        }

        if (hasChanged) {
            callback();
        }
        InternalCreact::effects[InternalCreact::effectID] = dep.value;
        InternalCreact::effectID++;
    }

    template <typename TDep, typename... TDeps>
    void useEffect(const std::function<void()> callback,
        const InternalCreact::State<TDep> &dep,
        const InternalCreact::State<TDeps> &...deps) {
        useEffect(callback, dep);
        useEffect(callback, deps...);
    }
}

#endif
// hook: useState, useEffect, useTimeout, useInterval, useKeyPress, useRef