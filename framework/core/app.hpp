#ifndef __FRAMEWORK_APP__
#define __FRAMEWORK_APP__

#include "window.hpp"
#include <vector>

class App
{
public:
    App &addWindow(const Window &window);
    int run() const;

private:
    std::vector<const Window> windows;
    void initWindows() const;
    void initColors() const;
};

#endif
