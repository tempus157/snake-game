#include "app.hpp"
#include <clocale>

App::App()
{
    progress = true;
    setlocale(LC_ALL, "");
}

App::~App()
{
    for (auto window : windows)
    {
        delete window;
    }
}

App *App::create()
{
    return new App();
}

App *App::attachWindow(Window *window)
{
    windows.push_back(window);
    return this;
}

void App::execute()
{
    while (progress)
    {
        // do someting
    }

    delete this;
}
