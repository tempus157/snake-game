#include "border.hpp"
#include <ncurses.h>

Border *Border::create()
{
    return new Border();
}

bool Border::isActive()
{
    return true;
}

void Border::render()
{
    if (color.hasValue)
    {
        attron(COLOR_PAIR(color.value.getAttribute()));
    }

    border(left, right, top, bottom, topLeft, topRight, bottomLeft, bottomRight);

    if (color.hasValue)
    {
        attroff(COLOR_PAIR(color.value.getAttribute()));
    }
}

Border *Border::setCharacter(unsigned int character)
{
    left = character;
    right = character;
    top = character;
    bottom = character;
    topLeft = character;
    topRight = character;
    bottomLeft = character;
    bottomRight = character;
    return this;
}

Border *Border::setLeft(unsigned int character)
{
    left = character;
    return this;
}

Border *Border::setRight(unsigned int character)
{
    right = character;
    return this;
}

Border *Border::setTop(unsigned int character)
{
    top = character;
    return this;
}

Border *Border::setBottom(unsigned int character)
{
    bottom = character;
    return this;
}

Border *Border::setTopLeft(unsigned int character)
{
    topLeft = character;
    return this;
}

Border *Border::setTopRight(unsigned int character)
{
    topRight = character;
    return this;
}

Border *Border::setBottomLeft(unsigned int character)
{
    bottomLeft = character;
    return this;
}

Border *Border::setBottomRight(unsigned int character)
{
    bottomRight = character;
    return this;
}

Border *Border::setColor(Optional<ColorPair> color)
{
    this->color = color;
    return this;
}

Border *Border::setColor(Color foreground, Color background)
{
    color = ColorPair(foreground, background);
    return this;
}
