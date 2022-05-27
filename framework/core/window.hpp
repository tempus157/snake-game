#ifndef __FRAMEWORK_WINDOW__
#define __FRAMEWORK_WINDOW__

#include "color.hpp"
#include "object.hpp"
#include "vector.hpp"

#include <functional>
#include <vector>
#include <ncurses.h>

class Window final
{
public:
    const std::function<void()> mount;
    const std::function<void()> update;
    const std::function<void()> destroy;

    Window(const std::function<void()> &mount,
           const std::function<void()> &update,
           const std::function<void()> &destroy);
};

class WindowData final
{
public:
    WindowData &setScale(const Vector &scale);
    WindowData &setScale(int x, int y);
    WindowData &setColor(const ColorPair color);
    WindowData &setColor(const Color &foreground, const Color &background);
    WindowData &use(const Object &object);
    Window done() const;

private:
    Vector scale;
    ColorPair color;
    std::vector<const Object> children;
};

#endif
