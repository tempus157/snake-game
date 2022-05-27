#include "../main.hpp"

Window *myWindow()
{
    auto border = new Border();
    border->color = ColorPair(Color::Yellow, Color::Blue);

    auto title = new Object();
    title->text = "C++ programming with ncurses";
    title->color = ColorPair(Color::Red, Color::Green);
    title->position = Vector(3, 4);

    return Window::create()
        ->setScale(80, 25)
        ->setColor(Color::Blue, Color::Yellow)
        ->setBorder(border)
        ->useObject(title);
}
