#ifndef __FRAMEWORK_CORE_WINDOW__
#define __FRAMEWORK_CORE_WINDOW__

#include "border.hpp"
#include "object.hpp"
#include "../utils/color.hpp"
#include "../utils/optional.hpp"
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
    Window *setBorder(Border border);
    Window *useObject(Object object);

    void init();
    void render();

private:
    Window();
    std::vector<Object> objects;
    Vector scale;
    ColorPair color;
    Optional<Border> border;
};

#endif
