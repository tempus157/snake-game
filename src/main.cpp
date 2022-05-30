#include "main.hpp"

int main() {
    return createApp()
        .useWindow(myWindow(Vector(0, 0), Vector(40, 25)))
        .useWindow(myWindow(Vector(45, 0), Vector(40, 25)))
        .run();
}
