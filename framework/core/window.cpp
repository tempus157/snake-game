#include "window.hpp"

Window::Window(const std::function<void()> &render) : window(initscr()), render(render) {}

WindowBuilder &WindowBuilder::setScale(const Vector &scale)
{
    this->scale = scale;
    return *this;
}

WindowBuilder &WindowBuilder::setColor(const ColorPair color)
{
    this->color = color;
    return *this;
}

WindowBuilder &WindowBuilder::use(const Object &object)
{
    children.push_back(object);
    return *this;
}

Window WindowBuilder::done() const
{
    const auto render = [=]
    {
        for (const auto &child : children)
        {
            child.render();
        }
    };

    return Window(render);
}