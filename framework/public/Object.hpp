#ifndef __FRAMEWORK_OBJECT__
#define __FRAMEWORK_OBJECT__

#include "../public/Vector.hpp"

#include <functional>
#include <vector>

class Object final {
public:
    const std::function<void(const Vector2 &)> update;
    Object(const std::function<void(const Vector2 &)> &update);
    Object(const std::vector<const Object> &objects);
};

#endif
