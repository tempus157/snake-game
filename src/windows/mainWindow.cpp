#include "mainWindow.hpp"

void MainWindow::init()
{
    setScale(80, 25);
    useObject(title);
    title->position = Vector(3, 4);
}

void MainWindow::update()
{
    tickCount++;
    title->text = std::to_string(tickCount);
}
