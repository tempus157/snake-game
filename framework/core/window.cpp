#include "window.hpp"

Window::Window(const std::function<void()> &init, const std::function<void()> &render)
    : init(init), render(render) {}

WindowCreator &WindowCreator::setScale(const Vector &scale)
{
    this->scale = scale;
    return *this;
}

WindowCreator &WindowCreator::setScale(int x, int y)
{
    this->scale.x = x;
    this->scale.y = y;
    return *this;
}

WindowCreator &WindowCreator::setColor(const ColorPair color)
{
    this->color = color;
    return *this;
}

WindowCreator &WindowCreator::setColor(const Color &foreground, const Color &background)
{
    this->color.foreground = foreground;
    this->color.background = background;
    return *this;
}

WindowCreator &WindowCreator::use(const Object &object)
{
    children.push_back(object);
    return *this;
}

Window WindowCreator::done() const
{
    const auto init = [=]
    {
        initscr();
        resize_term(scale.y, scale.x);
        bkgd(COLOR_PAIR(color.getAttribute()));
    };

    const auto render = [=]
    {
        clear();

        for (const auto &child : children)
        {
            child.render();
        }

        refresh();
    };

    return Window(init, render);
}