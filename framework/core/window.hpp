#ifndef __FRAMEWORK_CORE_WINDOW__
#define __FRAMEWORK_CORE_WINDOW__

#include "border.hpp"
#include "object.hpp"

#include "../utils/color.hpp"
#include "../utils/optional.hpp"
#include "../utils/vector.hpp"

#include <vector>
#include <ncurses.h>

class Window
{
public:
    ~Window();
    static Window *create();

    Window *setScale(const Vector &scale);
    Window *setScale(int x, int y);
    Window *setColor(ColorPair const &color);
    Window *setColor(const Color &foreground, const Color &background);
    Window *setBorder(const Border *border);
    Window *useObject(const Object *object);

    void init();
    void render() const;

private:
    Window();
    WINDOW *window;
    std::vector<const Object *> objects;
    Vector scale;
    ColorPair color;
    Optional<const Border *> border;
};

#endif
