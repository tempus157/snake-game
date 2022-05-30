#ifndef __FRAMEWORK_WINDOW_DATA__
#define __FRAMEWORK_WINDOW_DATA__

#include "../lib/ColorPair.hpp"
#include "../lib/Vector.hpp"

#include <ncurses.h>
#include <vector>

class Object;

class WindowData final {
public:
    void setPosition(const Vector &position);
    void setScale(const Vector &scale);
    void setColor(const ColorPair &color);
    void setBorderCh(char ch);
    void setBorderColor(const ColorPair &color);
    void useObjects(const std::vector<const Object> &objects);

    void mount();
    void update();
    void destroy();

private:
    Vector position;
    Vector scale;
    ColorPair color;
    char borderCh;
    ColorPair borderColor;
    std::vector<const Object> objects;
    WINDOW *window;
};

#endif
