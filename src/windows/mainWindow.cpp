#include "mainWindow.hpp"

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
}
