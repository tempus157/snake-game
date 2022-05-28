#include "main.hpp"

int main() {
    return createApp()
        .loadWindow(myWindow(Vector(0, 0), Vector(40, 25)))
        .loadWindow(myWindow(Vector(45, 0), Vector(40, 25)))
        .run();
}
