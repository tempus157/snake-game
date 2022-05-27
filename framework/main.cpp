#include "main.hpp"
#include <memory>

Object label(const std::string &text)
{
    auto render = [=]
    {
        printw(text.c_str());
    };

    return Object(render, [] {});
}

Object label(const std::string &text, const Vector &position)
{
    auto render = [=]
    {
        mvprintw(position.y, position.x, text.c_str());
    };

    return Object(render, [] {});
}

Object label(const std::string &text, const ColorPair &color)
{
    auto render = [=]
    {
        attron(COLOR_PAIR(color.getAttribute()));
        printw(text.c_str());
        attroff(COLOR_PAIR(color.getAttribute()));
    };

    return Object(render, [] {});
}

Object label(const std::string &text, const Vector &position, const ColorPair &color)
{
    auto render = [=]
    {
        attron(COLOR_PAIR(color.getAttribute()));
        mvprintw(position.y, position.x, text.c_str());
        attroff(COLOR_PAIR(color.getAttribute()));
    };

    return Object(render, [] {});
}

void onKeyPress(Key key, const std::function<void()> &fn)
{
    Input::addListener(key, fn);
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
