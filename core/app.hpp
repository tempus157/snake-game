#ifndef __CORE_APP__
#define __CORE_APP__

#include "window.hpp"
#include <vector>

class App
{
public:
    static App *create();
    App *attachWindow(Window *window);
    void execute();

private:
    static bool progress;
    std::vector<Window *> windows;

    App();
    ~App();
};

#endif
