#include "../main.hpp"

Scene gameScene() {
    return Object({
        $goto(Vector2(30, 0)),
        field(),
    });
}
