#include "scene.h"

int main() {
    return App()
        .setScale(Vector2(80, 25))
        .useScene("intro", introScene)
        .useScene("game", gameScene)
        .useScene("result", resultScene)
        .run("intro");
}
