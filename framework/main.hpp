#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./core/app.hpp"
#include "./core/color.hpp"
#include "./core/object.hpp"
#include "./core/optional.hpp"
#include "./core/state.hpp"
#include "./core/vector.hpp"
#include "./core/window.hpp"

#include <functional>
#include <memory>
#include <string>

ObjectData &createObject();
WindowData &createWindow();
App &createApp();

template <typename T>
State<T> useState() {
    return State<T>();
}

template <typename T>
State<T> useState(const T &value) {
    return State<T>(value);
}

State<std::string> useState(const char *value);

template <typename TDep>
void useEffect(const std::function<void()> &callback, State<TDep> dep) {
    decltype(dep)::onUpdate(dep, callback);
}

template <typename TDep, typename... TDeps>
void useEffect(const std::function<void()> &callback,
               State<TDep> dep, State<TDeps>... deps) {
    decltype(dep)::onUpdate(dep, callback);
    useEffect(callback, deps...);
}

void quitApp();
void onKeyPress(const Key &key,
                const std::function<void(const Key &)> &callback);

// TODO Make State<std::string> template where T supports std::to_string
Object label(const State<std::string> &text);
Object label(const State<std::string> &text, const State<Vector> &position);
Object label(const State<std::string> &text, const State<ColorPair> &color);

Object label(const State<std::string> &text,
             const State<Vector> &position,
             const State<ColorPair> &color);

#endif
