#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./core/app.hpp"
#include "./core/color.hpp"
#include "./core/input.hpp"
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

void onKeyPress(Key key, const std::function<void(Key)> &fn);
void quitApp();

// TODO Make it template where T is built-in type
Object label(const State<std::string> &text);
Object label(const State<std::string> &text, const State<Vector> &position);
Object label(const State<std::string> &text, const State<ColorPair> &color);
Object label(const State<std::string> &text, const State<Vector> &position, const State<ColorPair> &color);

#endif
