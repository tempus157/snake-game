#include "../main.hpp"

#include <deque>

Scene gameScene() {
    auto snakePosition = Property<std::deque<Vector2>>({
        Vector2(4, 0),
        Vector2(2, 0),
        Vector2(0, 0),
    });

    return Object({
        wall(),
        snake(snakePosition),

        // Snake position log
        $goto(Vector2::Zero),
        $for(snakePosition, [](const Vector2 &pos, int i) {
            return $union({
                $goto(Vector2(0, i)),
                label(std::to_string(pos.x) + "," + std::to_string(pos.y)),
            });
        }),
    });
}
