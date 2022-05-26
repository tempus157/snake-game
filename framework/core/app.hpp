#ifndef __FRAMEWORK_CORE_APP__
#define __FRAMEWORK_CORE_APP__

#include "window.hpp"
#include <vector>

class App
{
public:
    static App *create();
    App *useWindow(Window *window);
    int execute();

private:
    static bool progress;
    std::vector<Window::Hooks *> windowHooks;

    App();
    ~App();

    void initWindows();
    void initColors() const;
    void initInput() const;
    void startWindows() const;
    void updateWindows() const;
    void renderWindows() const;
};

#endif
