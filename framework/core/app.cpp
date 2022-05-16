#include "app.hpp"
#include "input.hpp"

#include <clocale>
#include <unistd.h>

bool App::progress = true;

App::App()
{
    setlocale(LC_ALL, "");
}

App::~App()
{
    for (auto window : windows)
    {
        delete window;
    }

    windows.clear();
}

App *App::create()
{
    return new App();
}

void App::quit()
{
    progress = false;
}

App *App::useWindow(Window *window)
{
    windows.push_back(window);
    return this;
}

int App::execute()
{
    initWindows();

    while (progress)
    {
        Input::readKey();
        updateWindows();
        renderWindows();
        usleep(20000);
    }

    releaseWindows();
    delete this;
    return 0;
}

void App::initWindows()
{
    for (auto window : windows)
    {
        window->init();
    }
}

void App::updateWindows()
{
    for (auto window : windows)
    {
        window->update();
    }
}

void App::renderWindows()
{
    for (auto window : windows)
    {
        window->render();
    }
}

void App::releaseWindows()
{
    for (auto window : windows)
    {
        window->release();
    }
}
