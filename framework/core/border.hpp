#ifndef __FRAMEWORK_CORE_BORDER__
#define __FRAMEWORK_CORE_BORDER__

#include "../utils/optional.hpp"
#include "../utils/color.hpp"

class Border
{
public:
    Border();
    Border(unsigned int const character);

    unsigned int left;
    unsigned int right;
    unsigned int top;
    unsigned int bottom;
    unsigned int topLeft;
    unsigned int topRight;
    unsigned int bottomLeft;
    unsigned int bottomRight;
    Optional<ColorPair> color;
};

#endif