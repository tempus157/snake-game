#include "window.hpp"

Window::~Window()
{
    endwin();
}

void Window::init() {}
void Window::update() {}
void Window::release() {}

void Window::render()
{
    wrefresh(window);
}
