#ifndef __FRAMEWORK_APP__
#define __FRAMEWORK_APP__

#include "input.hpp"
#include "vector.hpp"
#include "window.hpp"

#include <functional>
#include <vector>

class App final {
public:
    App();

    static void update();
    static void quit();
    App &setScale(const Vector &scale);
    App &setScale(int x, int y);
    App &loadWindow(const Window &window);
    int run() const;

private:
    static App *instance;
    bool progress = true;
    Vector scale;
    std::vector<const Window> windows;

    void mount() const;
    void receiveInput() const;
    void destroy() const;
};

#endif
