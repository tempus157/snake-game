#ifndef __FRAMEWORK_CORE_WINDOW__
#define __FRAMEWORK_CORE_WINDOW__

#include "object.hpp"
#include "../utils/color.hpp"
#include "../utils/vector.hpp"
#include <vector>

class Window
{
public:
    ~Window();
    static Window *create();

    Window *setScale(Vector scale);
    Window *setScale(int x, int y);
    Window *setColor(ColorPair color);
    Window *setColor(Color foreground, Color background);
    Window *useObject(IObject *object);

    void init();
    void render();

private:
    Window();
    std::vector<IObject *> objects;
    Vector scale;
    ColorPair color;
};

#endif
