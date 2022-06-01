#include "../main.hpp"

#include <algorithm>
#include <queue>

Object snake(Property<std::deque<Vector2>> &position,
    const Property<std::set<std::pair<int, int>>> &wallPosition) {
    auto direction = Property<Vector2>(Vector2::Right * 2);

    asyncLoop(100, [=]() mutable {
        const auto newPosition = position->front() + *direction;
        if (std::count(position->begin(), position->end(), newPosition) >= 1) {
            changeScene("result");
        }
        if (wallPosition->count({newPosition.x, newPosition.y}) >= 1) {
            changeScene("result");
        }

        position->pop_back();
        position->push_front(newPosition);
        position.set(*position);
    });

    onKeyPress(Key::UpArrow, [=]() mutable {
        direction.set(Vector2::Up);
    });

    onKeyPress(Key::DownArrow, [=]() mutable {
        direction.set(Vector2::Down);
    });

    onKeyPress(Key::LeftArrow, [=]() mutable {
        direction.set(Vector2::Left * 2);
    });

    onKeyPress(Key::RightArrow, [=]() mutable {
        direction.set(Vector2::Right * 2);
    });

    return Object({
        $goto(Vector2(0, 0)),
        $for(position, [](const Vector2 &pos, int i) {
            return $union({
                $goto(pos),
                label(i == 0 ? "ㅎ" : "ㅇ", Color::Yellow, Color::Black),
            });
        }),
    });
}
