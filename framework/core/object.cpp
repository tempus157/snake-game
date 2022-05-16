#include "object.hpp"

Object::Object() {}
Object::Object(std::string text) : text(text) {}

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
