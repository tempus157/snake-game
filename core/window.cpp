#include "window.hpp"

Window::Window()
{
    scale.x = getmaxx(window);
    scale.y = getmaxy(window);
}

Window::~Window()
{
    endwin();
}

void Window::render()
{
    clear();

    for (auto object : objects)
    {
        object->render();
    }

    border('*', '*', '*', '*', '*', '*', '*', '*');
    refresh();
}

void Window::init() {}
void Window::update() {}
void Window::release() {}

Vector Window::getScale()
{
    return scale;
}

void Window::setScale(Vector scale)
{
    setScale(scale.x, scale.y);
}

void Window::setScale(int x, int y)
{
    scale.x = x;
    scale.y = y;
    resize_term(y, x);
}

void Window::useObject(Object *object)
{
    objects.push_back(object);
}
