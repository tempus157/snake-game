#include "main.hpp"

int main() {
    return App()
        .setScale(Vector2(80, 25))
        .useScene("game", gameScene)
        .useScene("result", resultScene)
        .run("game");
}
