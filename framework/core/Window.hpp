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
    Window(const std::vector<const Object> &objects);
};

#endif
