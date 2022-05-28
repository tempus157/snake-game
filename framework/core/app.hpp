#ifndef __FRAMEWORK_APP__
#define __FRAMEWORK_APP__

#include "input.hpp"
#include "window.hpp"

#include <functional>
#include <vector>

class App final {
public:
    App();

    static void update();
    static void quit();
    App &loadWindow(const Window &window);
    int run() const;

private:
    static App *instance;
    bool progress = true;
    std::vector<const Window> windows;

    void mount() const;
    void receiveInput() const;
    void destroy() const;
};

#endif
