#ifndef __FRAMEWORK_WINDOW__
#define __FRAMEWORK_WINDOW__

#include "color.hpp"
#include "object.hpp"
#include "vector.hpp"

#include <functional>
#include <vector>
#include <ncurses.h>

class Window
{
public:
    Window(const std::function<void()> &render);
    const std::function<void()> render;

private:
    const WINDOW *window;
};

class WindowBuilder
{
public:
    WindowBuilder &setScale(const Vector &scale);
    WindowBuilder &setColor(const ColorPair color);
    WindowBuilder &use(const Object &object);
    Window done() const;

private:
    Vector scale;
    ColorPair color;
    std::vector<const Object> children;
};

#endif
