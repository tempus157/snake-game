#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./core/app.hpp"
#include "./core/color.hpp"
#include "./core/object.hpp"
#include "./core/optional.hpp"
#include "./core/property.hpp"
#include "./core/state.hpp"
#include "./core/vector.hpp"
#include "./core/window.hpp"

#include <functional>
#include <memory>
#include <string>

ObjectData &createObject();
WindowData &createWindow();
AppData &createApp();

template <typename T>
State<T> useState() {
    return State<T>();
}

template <typename T>
State<T> useState(const T &value) {
    return State<T>(value);
}

State<std::string> useState(const char *value);

void onKeyPress(const Key &key, const std::function<void(const Key &)> &fn);
void quitApp();

// TODO Make Property<std::string> template where T supports std::to_string
Object label(const Property<std::string> &text);
Object label(const Property<std::string> &text, const Property<Vector> &position);
Object label(const Property<std::string> &text, const Property<ColorPair> &color);

Object label(const Property<std::string> &text,
             const Property<Vector> &position,
             const Property<ColorPair> &color);

#endif
