#include "app.hpp"
#include <clocale>
#include <unistd.h>
#include <ncurses.h>

bool App::progress = true;

App::App()
{
    setlocale(LC_ALL, "");
}

App::~App()
{
    for (auto const window : windows)
    {
        delete window;
    }
}

App *App::create()
{
    return new App();
}

App *App::useWindow(Window *window)
{
    windows.push_back(window);
    return this;
}

int App::execute()
{
    initWindows();
    initColors();

    while (progress)
    {
        renderWindows();
        usleep(20000);
    }

    delete this;
    return 0;
}

void App::initWindows()
{
    for (auto const window : windows)
    {
        window->init();
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

void App::renderWindows() const
{
    for (auto const window : windows)
    {
        window->render();
    }
}
