#include "scene.h"

Scene introScene() {
    onKeyPress(Key::Y, [] {
        changeScene("game");
    });

    onKeyPress(Key::N, [] {
        quitApp();
    });

    return {{
        $goto(Vector2(0, 0)),
        label("Do you want to play Snake Game? (y / n)"),
    }};
}