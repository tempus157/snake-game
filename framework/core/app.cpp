#include "app.hpp"

#include <clocale>
#include <ncurses.h>

App &App::addWindow(const Window &window)
{
    windows.push_back(window);
    return *this;
}

int App::run() const
{
    initWindows();
    initColors();

    for (const auto &window : windows)
    {
        window.update();
    }

    getch();

    for (const auto &window : windows)
    {
        window.destroy();
    }

    delete this;
    return 0;
}

void App::initWindows() const
{
    setlocale(LC_ALL, "");

    for (const auto &window : windows)
    {
        window.mount();
    }
}

void App::initColors() const
{
    start_color();
    ColorPair color;

    for (auto foreground = 0; foreground < 8; foreground++)
    {
        for (auto background = 0; background < 8; background++)
        {
            color.foreground = static_cast<Color>(foreground);
            color.background = static_cast<Color>(background);
            init_pair(color.getAttribute(), foreground, background);
        }
    }
}
