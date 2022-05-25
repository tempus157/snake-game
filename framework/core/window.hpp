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

    Window *setScale(Vector const &scale);
    Window *setScale(int const x, int const y);
    Window *setColor(ColorPair const &color);
    Window *setColor(Color const &foreground, Color const &background);
    Window *setBorder(Border const *border);
    Window *useObject(Object const *object);

    void init();
    void render() const;

private:
    Window();
    WINDOW *window;
    std::vector<Object const *> objects;
    Vector scale;
    ColorPair color;
    Optional<Border const *> border;
};

#endif
