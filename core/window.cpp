#include "window.hpp"

Window::Window()
{
    window = initscr();
}

Window::~Window()
{
    endwin();
}

void Window::render()
{
    wrefresh(window);
}
