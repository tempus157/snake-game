#include "object.hpp"

Object::Object() : useColor(false) {}
Object::Object(std::string text) : text(text), useColor(false) {}

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

ColorPair Object::getColor()
{
    return color;
}

void Object::setColor(Color foreground, Color background)
{
    color.foreground = foreground;
    color.background = background;
    useColor = true;
}

void Object::useWindowColor()
{
    useColor = false;
}

void Object::render()
{
    if (useColor)
    {
        attron(COLOR_PAIR(color.getAttribute()));
    }

    mvprintw(position.y, position.x, text.c_str());

    if (useColor)
    {
        attroff(COLOR_PAIR(color.getAttribute()));
    }
}
