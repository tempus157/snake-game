#include "app.hpp"

#include <clocale>
#include <thread>
#include <chrono>

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
    initWindows();

    while (progress)
    {
        updateWindows();
        renderWindows();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    releaseWindows();
    delete this;
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
