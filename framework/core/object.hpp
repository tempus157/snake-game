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
    const std::function<void()> update;
    const std::function<void()> destroy;

    Object(const std::function<void()> &update,
           const std::function<void()> &destroy);
};

class ObjectData final
{
public:
    // ObjectCreator &onKeyPress(Key key, std::function<void()> callback);
    ObjectData &use(const Object &object);
    Object done() const;

private:
    std::vector<const Object> children;
};

#endif
