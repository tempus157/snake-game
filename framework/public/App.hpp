#ifndef __FRAMEWORK_APP__
#define __FRAMEWORK_APP__

#include "../public/Vector.hpp"
#include "Object.hpp"

class App final {
public:
    App &setScale(const Vector2 &scale);
    App &useObject(const Object &object);
    int run() const;
};

#endif
