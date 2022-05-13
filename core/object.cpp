#include "object.hpp"
#include <ncurses.h>

Object::Object() {}
Object::Object(std::string text) : text(text) {}

void Object::render()
{
    mvprintw(position.y, position.x, text.c_str());
}
