#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./core/app.hpp"
#include "./core/color.hpp"
#include "./core/object.hpp"
#include "./core/window.hpp"
#include "./core/vector.hpp"

#include <string>
#include <memory>

using string = std::string;

Object label(const string &text);
Object label(const string &text, const Vector &position);
Object label(const string &text, const ColorPair &color);
Object label(const string &text, const Vector &position, const ColorPair &color);

ObjectData &createObject();
WindowData &createWindow();
App &createApp();

#endif
