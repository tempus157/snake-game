#include "main.hpp"

int main()
{
    return App::create()
        ->useWindow(myWindow())
        ->execute();
}
