#include "mainWindow.hpp"
#include "../../framework/core/input.hpp"
#include "../../framework/core/app.hpp"
#include <ncurses.h>

void MainWindow::init()
{
    setScale(Vector(80, 25));
    setColor(ColorPair(Color::Blue, Color::Yellow));

    auto border = Window::Border('*');
    border.color = ColorPair(Color::Red, Color::Green);
    setBorder(border);

    useObject(title);
    title->position = Vector(1, 1);

    useObject(subTitle);
    subTitle->position = Vector(1, 1);
}

void MainWindow::update()
{
    if (Input::keyPressed())
    {
        App::quit();
    }
}
