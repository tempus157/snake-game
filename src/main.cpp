#include <ncurses.h>
#include "../core/app.hpp"
#include "./windows/mainWindow.hpp"

int main()
{
    App::create()
        ->attachWindow(new MainWindow())
        ->execute();
    return 0;
}
