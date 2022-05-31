#include "main.hpp"

int main() {
    return App()
        .setScale(Vector2(80, 25))
        .useScene("main", myScene)
        .useScene("sub", quitScene)
        .run("main");
}
