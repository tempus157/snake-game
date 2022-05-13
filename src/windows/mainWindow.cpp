#include "mainWindow.hpp"

void MainWindow::init()
{
    setScale(Vector(80, 25));
    useObject(title);
    title->setPosition(Vector(3, 4));
}

void MainWindow::update()
{
    tickCount++;
    title->setText(std::to_string(tickCount));
}
