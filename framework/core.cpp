#include "core.hpp"

App &App::create()
{
    return *new App();
}

App &App::useWindow(std::function<void()> window)
{
    return *this;
}

int App::execute()
{
    return 0;
}