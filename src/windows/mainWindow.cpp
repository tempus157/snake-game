#include "mainWindow.hpp"
#include "../../framework/core/input.hpp"
#include <ncurses.h>

void MainWindow::init()
{
    setScale(80, 25);
    useObject(title);
    title->setPosition(3, 4);
    title->setColor(Color::Red, Color::White);
}

void MainWindow::update()
{
    tickCount++;
    title->setText(std::to_string(tickCount));

    if (Input::keyPressed())
    {
        title->setText(std::string(1, static_cast<char>(Input::currentKey())));
    }
}
