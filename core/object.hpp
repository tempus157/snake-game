#ifndef __CORE_OBJECT__
#define __CORE_OBJECT__

#include "vector.hpp"
#include "color.hpp"
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

    ColorPair getColor();
    void setColor(Color foreground, Color background);
    void render();

private:
    std::string text;
    Vector position;
    ColorPair color;
};

#endif