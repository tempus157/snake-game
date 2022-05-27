#ifndef __FRAMEWORK_OBJECT__
#define __FRAMEWORK_OBJECT__

#include "color.hpp"
#include "optional.hpp"
#include "vector.hpp"

#include <functional>
#include <string>
#include <vector>

class Object final
{
public:
    Object(const std::function<void()> &render);
    const std::function<void()> render;
};

class ObjectCreator final
{
public:
    // ObjectCreator &onKeyPress(Key key, std::function<void()> callback);
    ObjectCreator &use(const Object &object);
    Object done() const;

private:
    std::vector<const Object> children;
};

#endif
