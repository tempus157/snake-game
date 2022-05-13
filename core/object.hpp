#ifndef __CORE_OBJECT__
#define __CORE_OBJECT__

#include "vector.hpp"
#include <string>

class Object
{
public:
    std::string text;
    Vector position;

    Object();
    Object(std::string text);
    void render();

private:
};

#endif