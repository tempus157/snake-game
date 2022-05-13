#ifndef __CORE_WINDOW__
#define __CORE_WINDOW__

#include <ncurses.h>

class Window
{
public:
    ~Window();
    void render();

    virtual void init();
    virtual void update();
    virtual void release();

private:
    WINDOW *window = initscr();
};

#endif
