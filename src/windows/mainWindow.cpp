#include "mainWindow.hpp"

void MainWindow::init()
{
    tickCount = 0;
}

void MainWindow::update()
{
    tickCount++;
    printf("%d ", tickCount);
}

void MainWindow::release()
{
    printf("End window");
}
