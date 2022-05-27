#include "app.hpp"
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
        window.render();
    }

    getch();
    endwin();
    return 0;
}

void App::initWindows() const
{
    for (const auto &window : windows)
    {
        window.init();
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
