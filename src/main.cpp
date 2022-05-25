#include <iostream>
#include "../framework/core.hpp"

Window *mainWindow()
{
    auto border = Border::create()
                      ->setCharacter('*')
                      ->setColor(Color::Yellow, Color::Blue);

    auto title = Label::create()
                     ->setText("C++ programming with ncurses")
                     ->setColor(Color::Red, Color::Green)
                     ->setPosition(3, 4);

    return Window::create()
        ->setScale(80, 25)
        ->setColor(Color::Blue, Color::Yellow)
        ->useObject(border)
        ->useObject(title);
}

int main()
{
    return App::create()
        ->useWindow(mainWindow())
        ->execute();
}