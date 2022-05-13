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
    resize_term(scale.y, scale.x);
}

void Window::useObject(Object *object)
{
    objects.push_back(object);
}
