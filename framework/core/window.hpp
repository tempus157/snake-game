#ifndef __FRAMEWORK_CORE__WINDOW__
#define __FRAMEWORK_CORE__WINDOW__

#include "../util/vector.hpp"
#include "object.hpp"

#include <ncurses.h>
#include <vector>

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
    void setScale(int x, int y);
    void useObject(Object *object);

private:
    WINDOW *window = initscr();
    Vector scale;
    std::vector<Object *> objects;
};

#endif
