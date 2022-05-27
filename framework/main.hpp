#ifndef __FRAMEWORK__
#define __FRAMEWORK__

#include "./core/app.hpp"
#include "./core/color.hpp"
#include "./core/object.hpp"
#include "./core/optional.hpp"
#include "./core/window.hpp"
#include "./core/vector.hpp"

#include <string>

using string = std::string;

Object label(string text, Optional<ColorPair> color = nullptr);
Object label(string text, Vector position, Optional<ColorPair> color = nullptr);
ObjectCreator &createObject();
WindowCreator &createWindow();
App &createApp();

#endif
