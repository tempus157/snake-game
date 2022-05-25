#include "core.hpp"

#include <clocale>
#include <unistd.h>
#include <ncurses.h>

const Vector Vector::zero = Vector(0, 0);
const Vector Vector::one = Vector(1, 1);
const Vector Vector::up = Vector(0, 1);
const Vector Vector::down = Vector(0, -1);
const Vector Vector::left = Vector(-1, 0);
const Vector Vector::right = Vector(1, 0);

Vector::Vector() {}
Vector::Vector(int x, int y) : x(x), y(y) {}

ColorPair::ColorPair() {}
ColorPair::ColorPair(Color foreground, Color background)
    : foreground(foreground), background(background) {}

short ColorPair::getAttribute()
{
    auto lhs = static_cast<int>(foreground) * 10;
    auto rhs = static_cast<int>(background);
    return lhs + rhs;
}

Object *Object::create()
{
    return new Object();
}

Object *Object::setText(std::string text)
{
    this->text = text;
    return this;
}

Object *Object::setPosition(Vector position)
{
    this->position = position;
    return this;
}

Object *Object::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
    return this;
}

Object *Object::setColor(ColorPair color)
{
    this->color = color;
    return this;
}

Object *Object::setColor(Color foreground, Color background)
{
    color = ColorPair(foreground, background);
    return this;
}

void Object::render()
{
    if (color.hasValue)
    {
        attron(COLOR_PAIR(color.value.getAttribute()));
    }

    mvprintw(position.y, position.x, text.c_str());

    if (color.hasValue)
    {
        attroff(COLOR_PAIR(color.value.getAttribute()));
    }
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

Window *Window::useObject(Object *object)
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

void Window::release()
{
    endwin();
}

bool App::progress = true;

App::App()
{
    setlocale(LC_ALL, "");
}

App::~App()
{
    for (auto window : windows)
    {
        delete window;
    }
}

App *App::create()
{
    return new App();
}

App *App::useWindow(Window *window)
{
    windows.push_back(window);
    return this;
}

int App::execute()
{
    initWindows();
    initColors();

    while (progress)
    {
        updateWindows();
        renderWindows();
        usleep(20000);
    }

    releaseWindows();
    delete this;
    return 0;
}

void App::initWindows()
{
    for (auto window : windows)
    {
        window->init();
    }
}

void App::initColors()
{
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

void App::updateWindows()
{
    for (auto window : windows)
    {
    }
}

void App::renderWindows()
{
    for (auto window : windows)
    {
        window->render();
    }
}

void App::releaseWindows()
{
    for (auto window : windows)
    {
        window->release();
    }
}
