#include "main.hpp"

int main() {
    return App()
        .setScale(Vector2(80, 25))
        .useWindow(myWindow(Vector2(0, 0), Vector2(40, 25)))
        .useWindow(myWindow(Vector2(45, 0), Vector2(40, 25)))
        .run();
}
