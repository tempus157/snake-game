#ifndef __FRAMEWORK_OBJECT__
#define __FRAMEWORK_OBJECT__

#include "../library/Color.hpp"
#include "../library/Vector.hpp"

#include <functional>
#include <ncurses.h>
#include <string>
#include <vector>

class Object final {
public:
    const std::function<void(WINDOW *)> update;
    const std::function<void()> destroy;

    Object(const std::function<void(WINDOW *)> &update,
        const std::function<void()> &destroy);
};

#endif
