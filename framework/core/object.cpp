#include "object.hpp"

Object::Object(const std::function<void()> &render) : render(render) {}

ObjectCreator &ObjectCreator::use(const Object &object)
{
    children.push_back(object);
    return *this;
}

Object ObjectCreator::done() const
{
    const auto render = [=]
    {
        for (const auto &child : children)
        {
            child.render();
        }
    };

    return Object(render);
}
