#ifndef __FRAMEWORK_WINDOW__
#define __FRAMEWORK_WINDOW__

#include "../lib/ColorPair.hpp"
#include "../lib/Vector.hpp"
#include "Object.hpp"

#include <functional>
#include <memory>
#include <ncurses.h>
#include <vector>

class WindowData;

class Window final {
public:
    const std::shared_ptr<WindowData> data;
    Window();

    Window &setPosition(const Vector &position);
    Window &setScale(const Vector &scale);
    Window &setColor(const ColorPair &color);
    Window &setBorderCh(char ch);
    Window &setBorderColor(const ColorPair &color);
    Window &useObjects(const std::vector<const Object> &objects);
};

#endif
