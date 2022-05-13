#include "mainWindow.hpp"
#include "../../framework/core/input.hpp"
#include "../../framework/core/app.hpp"
#include <ncurses.h>

void MainWindow::init()
{
    setScale(80, 25);
    setColor(Color::Blue, Color::Yellow);

    useObject(title);
    title->setPosition(1, 1);
    title->setColor(Color::Blue, Color::Yellow);

    useObject(subTitle);
    subTitle->setPosition(1, 2);
    subTitle->setColor(Color::Blue, Color::Yellow);
}

void MainWindow::update()
{
    if (Input::keyPressed())
    {
        App::quit();
    }
}
