#include "window.hpp"

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

Window *Window::setScale(Vector const scale)
{
    this->scale = scale;
    return this;
}

Window *Window::setScale(int const x, int const y)
{
    scale.x = x;
    scale.y = y;
    return this;
}

Window *Window::setColor(ColorPair const color)
{
    this->color = color;
    return this;
}

Window *Window::setColor(Color const foreground, Color const background)
{
    color.foreground = foreground;
    color.background = background;
    return this;
}

Window *Window::setBorder(Border const *border)
{
    this->border = border;
    return this;
}

Window *Window::useObject(Object const *object)
{
    objects.push_back(object);
    return this;
}

void Window::init()
{
    window = initscr();
    resize_term(scale.y, scale.x);
    bkgd(COLOR_PAIR(color.getAttribute()));
}

void Window::render() const
{
    clear();

    if (border.hasValue)
    {
        if (border.value->color.hasValue)
        {
            attron(COLOR_PAIR(border.value->color.value.getAttribute()));
        }

        border(border.value->left, border.value->right,
               border.value->top, border.value->bottom,
               border.value->topLeft, border.value->topRight,
               border.value->bottomLeft, border.value->bottomRight);

        if (border.value->color.hasValue)
        {
            attroff(COLOR_PAIR(border.value->color.value.getAttribute()));
        }
    }

    for (auto const object : objects)
    {
        if (object->color.hasValue)
        {
            attron(COLOR_PAIR(object->color.value.getAttribute()));
        }

        mvprintw(object->position.y, object->position.x, object->text.c_str());

        if (object->color.hasValue)
        {
            attroff(COLOR_PAIR(object->color.value.getAttribute()));
        }
    }

    refresh();
}
