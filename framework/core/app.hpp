#ifndef __FRAMEWORK_APP__
#define __FRAMEWORK_APP__

#include "input.hpp"
#include "window.hpp"

#include <vector>

class App final {
public:
    static App *instance;
    static void quit();
    App &useWindow(const Window &window);
    int run() const;
    void updateWindows() const;

private:
    static bool progress;
    const Input input = Input();
    std::vector<const Window> windows;
    void mountWindows() const;
};

#endif
