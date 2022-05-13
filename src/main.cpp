#include "../core/app.hpp"
#include "./windows/mainWindow.hpp"

int main()
{
    App::create()
        ->useWindow(new MainWindow())
        ->execute();
    return 0;
}
