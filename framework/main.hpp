#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./core/app.hpp"
#include "./core/color.hpp"
#include "./core/input.hpp"
#include "./core/object.hpp"
#include "./core/optional.hpp"
#include "./core/property.hpp"
#include "./core/vector.hpp"
#include "./core/window.hpp"

#include <functional>
#include <memory>
#include <string>

ObjectData &createObject();
WindowData &createWindow();
App &createApp();

template <typename T>
Property<T> useProperty() {
    return Property<T>();
}

template <typename T>
Property<T> useProperty(const T &value) {
    return Property<T>(value);
}

Property<std::string> useProperty(const char *value);

void onKeyPress(Key key, const std::function<void(Key)> &fn);
void quitApp();

// TODO Make Property<std::string> template where T supports std::to_string
Object label(const Property<std::string> &text);
Object label(const Property<std::string> &text, const Property<Vector> &position);
Object label(const Property<std::string> &text, const Property<ColorPair> &color);

Object label(const Property<std::string> &text,
             const Property<Vector> &position,
             const Property<ColorPair> &color);

#endif
