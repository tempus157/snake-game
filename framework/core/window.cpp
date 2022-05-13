#include "window.hpp"

Window::Border::Border() : topLeft(' '), topMid(' '), topRight(' '),
                           midLeft(' '), midRight(' '), bottomLeft(' '),
                           bottomMid(' '), bottomRight(' ') {}

Window::Border::Border(unsigned int ch) : topLeft(ch), topMid(ch), topRight(ch),
                                          midLeft(ch), midRight(ch), bottomLeft(ch),
                                          bottomMid(ch), bottomRight(ch) {}

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
        renderBorder();
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

void Window::setScale(int x, int y)
{
    scale.x = x;
    scale.y = y;
    resize_term(y, x);
}

ColorPair Window::getColor()
{
    return color;
}

void Window::setColor(Color foreground, Color background)
{
    color.foreground = foreground;
    color.background = background;
    bkgd(COLOR_PAIR(color.getAttribute()));
}

void Window::useBorder(Border border)
{
    this->border = border;
}

void Window::useNoBorder()
{
    border = nullptr;
}

void Window::renderBorder()
{
    if (border.value.color)
    {
        attron(COLOR_PAIR(border.value.color.value.getAttribute()));
    }

    border(border.value.midLeft, border.value.midRight,
           border.value.topMid, border.value.bottomMid,
           border.value.topLeft, border.value.topRight,
           border.value.bottomLeft, border.value.bottomRight);

    if (border.value.color)
    {
        attroff(COLOR_PAIR(border.value.color.value.getAttribute()));
    }
}