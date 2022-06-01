#include "../main.hpp"

Object logger(const Property<std::deque<Vector2>> &snakePosition) {
    return Object({
        $goto(Vector2(0, 0)),
        $for(snakePosition, [](const Vector2 &pos, int i) {
            return $union({
                $goto(Vector2(0, i)),
                label(std::to_string(pos.x) + "," + std::to_string(pos.y)),
            });
        }),
    });
}
