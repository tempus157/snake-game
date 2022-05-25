#include <iostream>
#include "../framework/core.hpp"

Window *mainWindow()
{
    auto title = Object::create()
                     ->setText("C++ programming with ncurses")
                     ->setColor(Color::Red, Color::Green)
                     ->setPosition(3, 4);

    return Window::create()
        ->setScale(80, 25)
        ->setColor(Color::Blue, Color::Yellow)
        ->useObject(title);
}

int main()
{
    return App::create()
        ->useWindow(mainWindow())
        ->execute();
}