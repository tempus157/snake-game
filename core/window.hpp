#ifndef __CORE_WINDOW__
#define __CORE_WINDOW__

#include <ncurses.h>

class Window
{
public:
    Window();
    ~Window();

    virtual void init();
    virtual void update();
    virtual void release();
    void render();

private:
    WINDOW *window;
};

#endif
