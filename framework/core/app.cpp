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
    for (auto hooks : windowHooks)
    {
        delete hooks;
    }
}

App *App::create()
{
    return new App();
}

App *App::useWindow(Window *window)
{
    windowHooks.push_back(new Window::Hooks(window));
    return this;
}

int App::execute()
{
    initWindows();
    initColors();
    initInput();

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
    for (auto hooks : windowHooks)
    {
        hooks->init();
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

void App::initInput() const
{
    keypad(stdscr, true);
    nodelay(stdscr, true);
    curs_set(0);
    noecho();
}

void App::renderWindows() const
{
    for (auto hooks : windowHooks)
    {
        hooks->render();
    }
}
