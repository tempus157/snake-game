#include "main.hpp"
#include <memory>

Object label(string text, Optional<ColorPair> color)
{
    auto render = [=]
    {
        if (color.hasValue)
        {
            attron(COLOR_PAIR(color.value.getAttribute()));
        }

        printw(text.c_str());

        if (color.hasValue)
        {
            attroff(COLOR_PAIR(color.value.getAttribute()));
        }
    };

    return Object(render, [] {});
}

Object label(string text, Vector position, Optional<ColorPair> color)
{
    auto render = [=]
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
    };

    return Object(render, [] {});
}

ObjectData &createObject()
{
    return *new ObjectData();
}

WindowData &createWindow()
{
    return *new WindowData();
}

App &createApp()
{
    return *new App();
}
