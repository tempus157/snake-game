#include "object.hpp"

Object::Object() {}
Object::Object(std::string text) : text(text) {}

std::string Object::getText()
{
    return text;
}

void Object::setText(std::string text)
{
    this->text = text;
}

Vector Object::getPosition()
{
    return position;
}

void Object::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
}

Optional<ColorPair> Object::getColor()
{
    return color;
}

void Object::setColor(Color foreground, Color background)
{
    color = ColorPair(foreground, background);
}

void Object::useWindowColor()
{
    color = nullptr;
}

void Object::render()
{
    if (color)
    {
        attron(COLOR_PAIR(color.value.getAttribute()));
    }

    mvprintw(position.y, position.x, text.c_str());

    if (color)
    {
        attroff(COLOR_PAIR(color.value.getAttribute()));
    }
}
