#include "main.hpp"
#include <memory>

Object label(const string &text)
{
    auto render = [=]
    {
        printw(text.c_str());
    };

    return Object(render, [] {});
}

Object label(const string &text, const Vector &position)
{
    auto render = [=]
    {
        mvprintw(position.y, position.x, text.c_str());
    };

    return Object(render, [] {});
}

Object label(const string &text, const ColorPair &color)
{
    auto render = [=]
    {
        attron(COLOR_PAIR(color.getAttribute()));
        printw(text.c_str());
        attroff(COLOR_PAIR(color.getAttribute()));
    };

    return Object(render, [] {});
}

Object label(const string &text, const Vector &position, const ColorPair &color)
{
    auto render = [=]
    {
        attron(COLOR_PAIR(color.getAttribute()));
        mvprintw(position.y, position.x, text.c_str());
        attroff(COLOR_PAIR(color.getAttribute()));
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
