#include "window.hpp"
#include <ncurses.h>

Window::Window() {}

Window::~Window()
{
    for (auto const object : objects)
    {
        delete object;
    }

    endwin();
}

Window *Window::create()
{
    return new Window();
}

Window *Window::setScale(Vector scale)
{
    this->scale = scale;
    return this;
}

Window *Window::setScale(int x, int y)
{
    scale.x = x;
    scale.y = y;
    return this;
}

Window *Window::setColor(ColorPair color)
{
    this->color = color;
    return this;
}

Window *Window::setColor(Color foreground, Color background)
{
    color.foreground = foreground;
    color.background = background;
    return this;
}

Window *Window::useObject(IObject *object)
{
    objects.push_back(object);
    return this;
}

void Window::init()
{
    initscr();
    resize_term(scale.y, scale.x);
    bkgd(COLOR_PAIR(color.getAttribute()));
}

void Window::render()
{
    clear();

    for (auto object : objects)
    {
        object->render();
    }

    refresh();
}
