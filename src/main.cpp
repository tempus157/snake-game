#include "main.hpp"

int main() {
    return App()
        .setScale(Vector2(80, 25))
        .useObject(myObject())
        .run();
}
