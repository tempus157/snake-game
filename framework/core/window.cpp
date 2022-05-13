#include "window.hpp"

Window::Window()
{
    scale.x = getmaxx(window);
    scale.y = getmaxy(window);

    nodelay(window, true);
    start_color();
    ColorPair color;

    for (auto foreground = 0; foreground < 8; foreground++)
    {
        for (auto background = 0; background < 8; background++)
        {
            color.foreground = static_cast<Color>(foreground);
            color.background = static_cast<Color>(background);
            init_pair(color.getAttribute(), foreground, background);
        }
    }
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

    refresh();
}

void Window::init() {}
void Window::update() {}
void Window::release() {}

Vector Window::getScale()
{
    return scale;
}

void Window::setScale(int x, int y)
{
    scale.x = x;
    scale.y = y;
    resize_term(y, x);
}

Color Window::getBackgroundColor()
{
    return color.background;
}

void Window::setBackgroundColor(Color color)
{
    this->color.background = color;
    this->color.foreground = color;
    bkgd(COLOR_PAIR(this->color.getAttribute()));
}

void Window::useObject(Object *object)
{
    objects.push_back(object);
}
