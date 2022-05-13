#ifndef __CORE_WINDOW__
#define __CORE_WINDOW__

#include "vector.hpp"
#include <ncurses.h>

class Window
{
public:
    Window();
    ~Window();
    void render();

    virtual void init();
    virtual void update();
    virtual void release();

protected:
    Vector getScale();
    void setScale(Vector scale);
    void setScale(int x, int y);

private:
    WINDOW *window = initscr();
    Vector scale;
};

#endif
