#include "mainWindow.hpp"

void MainWindow::init()
{
    setScale(80, 25);
}

void MainWindow::update()
{
    tickCount++;
    printf("%d ", tickCount);
}
