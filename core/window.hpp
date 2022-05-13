#ifndef __CORE_WINDOW__
#define __CORE_WINDOW__

#include "vector.hpp"
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
    void setScale(Vector scale);
    void useObject(Object *object);

private:
    WINDOW *window = initscr();
    Vector scale;
    std::vector<Object *> objects;
};

#endif
