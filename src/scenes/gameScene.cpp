#include "../main.hpp"

Scene gameScene() {
    return Object({
        $goto(Vector2(10, 10)),
        field(),
    });
}
