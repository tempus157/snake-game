#include "core.hpp"
#include <ncurses.h>

const Vector Vector::zero = Vector(0, 0);
const Vector Vector::one = Vector(1, 1);
const Vector Vector::up = Vector(0, 1);
const Vector Vector::down = Vector(0, -1);
const Vector Vector::left = Vector(-1, 0);
const Vector Vector::right = Vector(1, 0);

Vector::Vector() {}
Vector::Vector(int x, int y) : x(x), y(y) {}

Object &Object::create()
{
    return *new Object();
}

Object &Object::setText(std::string text)
{
    this->text = text;
    return *this;
}

Object &Object::setPosition(Vector position)
{
    this->position = position;
    return *this;
}

Object &Object::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
    return *this;
}

Window &Window::create()
{
    return *new Window();
}

Window &Window::setScale(Vector scale)
{
    resize_term(scale.y, scale.x);
    return *this;
}

Window &Window::setScale(int x, int y)
{
    resize_term(y, x);
    return *this;
}

Window &Window::useObject(Object const &object)
{
    objects.push_back(object);
    return *this;
}

App &App::create()
{
    return *new App();
}

App &App::useWindow(std::function<Window()> window)
{
    return *this;
}

int App::execute()
{
    return 0;
}