#ifndef __FRAMEWORK_APP__
#define __FRAMEWORK_APP__

#include "input.hpp"
#include "window.hpp"

#include <vector>

class App final {
    template <typename T>
    friend class State;

public:
    App();
    static void quit();
    App &useWindow(const Window &window);
    int run() const;

private:
    static App *instance;
    bool progress = true;
    std::vector<const Window> windows;

    void mountWindows() const;
    void updateWindows() const;
};

#endif
