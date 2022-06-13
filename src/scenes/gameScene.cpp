#include "../libs/map.hpp"
#include "../main.hpp"

Scene gameScene() {
    auto map = Property<Map>();
    if (!map->loadLevel(0)) {
        quitApp();
    }

    return Object({
        $goto(Vector2(30, 0)),
        wall(map),
        $goto(Vector2(30, 0)),
        snake(map),
    });
}
