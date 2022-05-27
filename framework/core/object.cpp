#include "object.hpp"

Object::Object(std::function<void()> render) : render(render) {}

void Object::operator()() const
{
    render();
}

ObjectCreator &ObjectCreator::use(const Object &object)
{
    children.push_back(object);
    return *this;
}

Object ObjectCreator::done() const
{
    auto render = [=]
    {
        for (const auto &child : children)
        {
            child();
        }
    };

    return Object(render);
}
