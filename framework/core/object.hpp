#ifndef __FRAMEWORK_CORE_OBJECT__
#define __FRAMEWORK_CORE_OBJECT__

#include "../utils/vector.hpp"
#include "../utils/optional.hpp"
#include "../utils/color.hpp"
#include <string>

class Object
{
public:
    std::string text;
    Vector position;
    Optional<ColorPair> color;
};

#endif
