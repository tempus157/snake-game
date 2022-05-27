#ifndef __FRAMEWORK_OBJECT__
#define __FRAMEWORK_OBJECT__

#include "color.hpp"
#include "optional.hpp"
#include "vector.hpp"

#include <functional>
#include <string>
#include <vector>

#include <ncurses.h>

class Object final
{
public:
    Object(std::function<void()> render);
    void operator()() const;

private:
    std::function<void()> render;
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