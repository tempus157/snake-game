#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./core/app.hpp"
#include "./core/color.hpp"
#include "./core/object.hpp"
#include "./core/optional.hpp"
#include "./core/window.hpp"
#include "./core/vector.hpp"

#include <string>
#include <memory>

using string = std::string;

Object label(const string &text, const Optional<ColorPair> &color = nullptr);
Object label(const string &text, const Vector &position, const Optional<ColorPair> &color = nullptr);

ObjectData &createObject();
WindowData &createWindow();
App &createApp();

#endif
