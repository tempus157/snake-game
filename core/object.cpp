#include "object.hpp"
#include <ncurses.h>

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

void Object::setPosition(Vector position)
{
    this->position = position;
}

void Object::render()
{
    mvprintw(position.y, position.x, text.c_str());
}
