#ifndef __FRAMEWORK_CORE_OBJECT__
#define __FRAMEWORK_CORE_OBJECT__

#include "../utils/vector.hpp"
#include "../utils/color.hpp"
#include "../utils/optional.hpp"

#include <ncurses.h>
#include <string>

class Object
{
public:
    Object();
    Object(std::string text);

    std::string getText();
    void setText(std::string text);
    Vector getPosition();
    void setPosition(int x, int y);

    Optional<ColorPair> getColor();
    void setColor(Color foreground, Color background);
    void useWindowColor();
    void render();

private:
    std::string text;
    Vector position;
    Optional<ColorPair> color;
};

#endif