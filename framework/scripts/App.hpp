#ifndef __FRAMEWORK_APP__
#define __FRAMEWORK_APP__

#include "../library/Vector.hpp"
#include "Window.hpp"

#include <functional>
#include <vector>

class App final {
public:
    App &setScale(const Vector &scale);
    App &useWindow(const Window &window);
    int run() const;

    // TEMP
    static void update();
};

#endif
