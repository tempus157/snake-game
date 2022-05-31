#include "../main.hpp"

#include <queue>

Object snake(Property<std::deque<Vector2>> &position,
    const Property<std::set<std::pair<int, int>>> &wallPosition) {
    auto direction = Property<Vector2>(Vector2::Right * 2);

    asyncLoop(100, [=]() mutable {
        const auto head = position->front();
        const auto newPosition = head + *direction;
        if (wallPosition->count({newPosition.x, newPosition.y})) {
            changeScene("result");
        }

        position->pop_back();
        position->push_front(newPosition);
        position.set(*position);
    });

    onKeyPress(Key::UpArrow, [=]() mutable {
        if (*direction == Vector2::Down) {
            changeScene("result");
        }
        direction.set(Vector2::Up);
    });

    onKeyPress(Key::DownArrow, [=]() mutable {
        if (*direction == Vector2::Up) {
            changeScene("result");
        }
        direction.set(Vector2::Down);
    });

    onKeyPress(Key::LeftArrow, [=]() mutable {
        if (*direction == Vector2::Right * 2) {
            changeScene("result");
        }
        direction.set(Vector2::Left * 2);
    });

    onKeyPress(Key::RightArrow, [=]() mutable {
        if (*direction == Vector2::Left * 2) {
            changeScene("result");
        }
        direction.set(Vector2::Right * 2);
    });

    return Object({
        $for(position, [](const Vector2 &pos, int i) {
            return $union({
                $goto(pos),
                label(i == 0 ? "ㅎ" : "ㅇ"),
            });
        }),
    });
}
