#include "label.hpp"
#include <ncurses.h>

Label *Label::create()
{
    return new Label();
}

Label *Label::setText(std::string text)
{
    this->text = text;
    return this;
}

Label *Label::setPosition(Vector position)
{
    this->position = position;
    return this;
}

Label *Label::setPosition(int x, int y)
{
    position.x = x;
    position.y = y;
    return this;
}

Label *Label::setColor(Optional<ColorPair> color)
{
    this->color = color;
    return this;
}

Label *Label::setColor(Color foreground, Color background)
{
    color = ColorPair(foreground, background);
    return this;
}

bool Label::isActive()
{
    return true;
}

void Label::render()
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
