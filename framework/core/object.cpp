#include "object.hpp"

Object::Object(const std::function<void()> &update,
               const std::function<void()> &destroy)
    : update(update), destroy(destroy) {}

ObjectData &ObjectData::use(const Object &object)
{
    children.push_back(object);
    return *this;
}

Object ObjectData::done() const
{
    const auto update = [&]
    {
        for (const auto &child : children)
        {
            child.update();
        }
    };

    const auto destroy = [&]
    {
        for (const auto &child : children)
        {
            child.destroy();
        }

        delete this;
    };

    return Object(update, destroy);
}
