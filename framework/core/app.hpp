#ifndef __FRAMEWORK_CORE_APP__
#define __FRAMEWORK_CORE_APP__

#include "window.hpp"
#include <vector>

class App
{
public:
    static App *create();
    App *useWindow(Window *window);
    void execute();

private:
    static bool progress;
    std::vector<Window *> windows;

    App();
    ~App();

    void initWindows();
    void updateWindows();
    void renderWindows();
    void releaseWindows();
};

#endif
