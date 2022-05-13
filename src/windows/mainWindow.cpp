#include "mainWindow.hpp"
#include "../../framework/core/input.hpp"
#include "../../framework/core/app.hpp"
#include <ncurses.h>

void MainWindow::init()
{
    setScale(80, 25);
    setColor(Color::Blue, Color::Yellow);

    auto border = Window::Border('*');
    border.color = ColorPair(Color::Red, Color::Green);
    useBorder(border);

    useObject(title);
    title->setPosition(1, 1);

    useObject(subTitle);
    subTitle->setPosition(1, 2);
}

void MainWindow::update()
{
    if (Input::keyPressed())
    {
        App::quit();
    }
}
