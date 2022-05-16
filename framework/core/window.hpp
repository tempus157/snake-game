#ifndef __FRAMEWORK_CORE__WINDOW__
#define __FRAMEWORK_CORE__WINDOW__

#include "object.hpp"

#include "../utils/color.hpp"
#include "../utils/vector.hpp"
#include "../utils/optional.hpp"

#include <ncurses.h>
#include <vector>

class Window
{
public:
    struct Border
    {
    public:
        unsigned int topLeft;
        unsigned int topMid;
        unsigned int topRight;
        unsigned int midLeft;
        unsigned int midRight;
        unsigned int bottomLeft;
        unsigned int bottomMid;
        unsigned int bottomRight;
        Optional<ColorPair> color;

        Border();
        Border(unsigned int ch);
        void render();
    };

    Window();
    ~Window();

    void render();
    virtual void init() {}
    virtual void update() {}
    virtual void release() {}

protected:
    void useObject(Object *object);
    Vector getScale();
    void setScale(int x, int y);

    ColorPair getColor();
    void setColor(Color foreground, Color background);
    void useBorder(Border border);
    void useNoBorder();

private:
    WINDOW *window = initscr();
    std::vector<Object *> objects;
    Vector scale;
    ColorPair color;
    Optional<Border> border;
};

#endif
