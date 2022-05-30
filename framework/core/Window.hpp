#ifndef __FRAMEWORK_WINDOW__
#define __FRAMEWORK_WINDOW__

#include "../lib/Color.hpp"
#include "../lib/ColorPair.hpp"
#include "../lib/Vector.hpp"
#include "Object.hpp"

#include <functional>
#include <ncurses.h>
#include <vector>

class Window final {
public:
    const std::function<void()> mount;
    const std::function<void()> update;
    const std::function<void()> destroy;

    Window(const Vector &position,
        const Vector &scale,
        const std::vector<const Object> &objects);

private:
    WINDOW *window;
};

#endif
