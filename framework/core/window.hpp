#ifndef __FRAMEWORK_WINDOW__
#define __FRAMEWORK_WINDOW__

#include "color.hpp"
#include "object.hpp"
#include "optional.hpp"
#include "vector.hpp"

#include <functional>
#include <ncurses.h>
#include <vector>

class Border final {
public:
    unsigned int left;
    unsigned int right;
    unsigned int top;
    unsigned int bottom;
    unsigned int topLeft;
    unsigned int topRight;
    unsigned int bottomLeft;
    unsigned int bottomRight;
    Optional<ColorPair> color;

    Border();
    Border(unsigned int character);
    void update() const;
};

class Window final {
public:
    const std::function<void()> mount;
    const std::function<void()> update;
    const std::function<void()> destroy;

    Window(const std::function<void()> &mount,
           const std::function<void()> &update,
           const std::function<void()> &destroy);
};

// TODO Make window properties Window<T>
class WindowData final {
public:
    WindowData &setScale(const Vector &scale);
    WindowData &setScale(int x, int y);
    WindowData &setColor(const ColorPair color);
    WindowData &setColor(const Color &foreground, const Color &background);
    WindowData &setBorder(const Optional<Border> &border);
    WindowData &useObject(const Object &object);
    Window done() const;

private:
    Vector scale;
    ColorPair color;
    Optional<Border> border;
    std::vector<const Object> objects;
};

#endif
