#ifndef __CORE_OBJECT__
#define __CORE_OBJECT__

#include "vector.hpp"
#include <string>

class Object
{
public:
    Object();
    Object(std::string text);

    std::string getText();
    void setText(std::string text);
    Vector getPosition();
    void setPosition(Vector position);
    void render();

private:
    std::string text;
    Vector position;
};

#endif