#ifndef __FRAMEWORK_CORE__
#define __FRAMEWORK_CORE__

#include <functional>

class App
{
public:
    static App &create();
    App &useWindow(std::function<void()> window);
    int execute();
};

#endif
