#include <iostream>
#include "../framework/core.hpp"

int main()
{
    return App::create()
        .useWindow([]()
                   { std::cout << "Hello, world!" << std::endl; })
        .execute();
}