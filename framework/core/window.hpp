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
    Window(const std::function<void()> &init, const std::function<void()> &render);
    const std::function<void()> init;
    const std::function<void()> render;
};

class WindowCreator
{
public:
    WindowCreator &setScale(const Vector &scale);
    WindowCreator &setScale(int x, int y);
    WindowCreator &setColor(const ColorPair color);
    WindowCreator &setColor(const Color &foreground, const Color &background);
    WindowCreator &use(const Object &object);
    Window done() const;

private:
    Vector scale;
    ColorPair color;
    std::vector<const Object> children;
};

#endif
