#include "window.hpp"

Window::Window() {}

Window::~Window()
{
    for (auto object : objects)
    {
        delete object;
    }

    endwin();
}

Window *Window::create()
{
    return new Window();
}

Window *Window::setScale(const Vector &scale)
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

Window *Window::setColor(const ColorPair &color)
{
    this->color = color;
    return this;
}

Window *Window::setColor(const Color &foreground, const Color &background)
{
    color.foreground = foreground;
    color.background = background;
    return this;
}

Window *Window::setBorder(const Border *border)
{
    this->border = border;
    return this;
}

Window *Window::useObject(const Object *object)
{
    objects.push_back(object);
    return this;
}

Window::Hooks::Hooks(Window *window) : window(window) {}

Window::Hooks::~Hooks()
{
    delete window;
}

void Window::Hooks::init()
{
    window->window = initscr();
    resize_term(window->scale.y, window->scale.x);
    bkgd(COLOR_PAIR(window->color.getAttribute()));
}

void Window::Hooks::render() const
{
    clear();

    if (window->border.hasValue)
    {
        renderBorder(window->border.value);
    }

    renderObjects();
    refresh();
}

void Window::Hooks::renderBorder(const Border *border) const
{
    if (border->color.hasValue)
    {
        attron(COLOR_PAIR(border->color.value.getAttribute()));
    }

    border(border->left, border->right, border->top, border->bottom,
           border->topLeft, border->topRight, border->bottomLeft, border->bottomRight);

    if (border->color.hasValue)
    {
        attroff(COLOR_PAIR(border->color.value.getAttribute()));
    }
}

void Window::Hooks::renderObjects() const
{
    for (auto object : window->objects)
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
}
