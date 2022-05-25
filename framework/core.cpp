#include "core.hpp"

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

App &App::create()
{
    return *new App();
}

App &App::useWindow(std::function<void()> window)
{
    return *this;
}

int App::execute()
{
    return 0;
}