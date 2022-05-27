#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./core/app.hpp"
#include "./core/color.hpp"
#include "./core/input.hpp"
#include "./core/object.hpp"
#include "./core/optional.hpp"
#include "./core/vector.hpp"
#include "./core/window.hpp"

#include <functional>
#include <memory>
#include <string>

Object label(const std::string &text);
Object label(const std::string &text, const Vector &position);
Object label(const std::string &text, const ColorPair &color);
Object label(const std::string &text, const Vector &position, const ColorPair &color);

void onKeyPress(Key key, const std::function<void(Key)> &fn);

ObjectData &createObject();
WindowData &createWindow();
App &createApp();

#endif
