#include "../framework/core/app.hpp"
#include "./windows/mainWindow.hpp"

int main()
{
    return App::create()
        ->useWindow(new MainWindow())
        ->execute();
}
