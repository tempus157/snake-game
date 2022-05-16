#include "window.hpp"

Window::Border::Border() : topLeft(' '), topMid(' '), topRight(' '),
                           midLeft(' '), midRight(' '), bottomLeft(' '),
                           bottomMid(' '), bottomRight(' ') {}

Window::Border::Border(unsigned int ch) : topLeft(ch), topMid(ch), topRight(ch),
                                          midLeft(ch), midRight(ch), bottomLeft(ch),
                                          bottomMid(ch), bottomRight(ch) {}

void Window::Border::render()
{
    if (color)
    {
        attron(COLOR_PAIR(color.value.getAttribute()));
    }

    border(midLeft, midRight, topMid, bottomMid,
           topLeft, topRight, bottomLeft, bottomRight);

    if (color)
    {
        attroff(COLOR_PAIR(color.value.getAttribute()));
    }
}

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
    for (auto object : objects)
    {
        delete object;
    }

    objects.clear();
    endwin();
}

void Window::render()
{
    clear();

    if (border)
    {
        border.value.render();
    }

    for (auto object : objects)
    {
        object->render();
    }

    refresh();
}

void Window::useObject(Object *object)
{
    objects.push_back(object);
}

Vector Window::getScale()
{
    return scale;
}

void Window::setScale(Vector scale)
{
    this->scale.x = scale.x;
    this->scale.y = scale.y;
    resize_term(scale.y, scale.x);
}

ColorPair Window::getColor()
{
    return color;
}

void Window::setColor(ColorPair color)
{
    this->color.foreground = color.foreground;
    this->color.background = color.background;
    bkgd(COLOR_PAIR(color.getAttribute()));
}

Optional<Window::Border> Window::getBorder()
{
    return border;
}

void Window::setBorder(Optional<Window::Border> border)
{
    this->border = border;
}
