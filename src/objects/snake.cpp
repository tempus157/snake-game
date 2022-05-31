#include "../main.hpp"

#include <queue>

Object snake() {
    auto direction = Property<Vector2>(Vector2::Right * 2);
    auto position = Property<std::deque<Vector2>>({
        Vector2(0, 0),
        Vector2(1, 0),
        Vector2(2, 0),
    });

    asyncLoop(100, [=]() mutable {
        auto head = position->back();
        position->pop_front();
        position->push_back(head + *direction);
        position.set(*position);
    });

    onKeyPress(Key::UpArrow, [=]() mutable {
        direction.set(Vector2::Down);
    });

    onKeyPress(Key::DownArrow, [=]() mutable {
        direction.set(Vector2::Up);
    });

    onKeyPress(Key::LeftArrow, [=]() mutable {
        direction.set(Vector2::Left * 2);
    });

    onKeyPress(Key::RightArrow, [=]() mutable {
        direction.set(Vector2::Right * 2);
    });

    return Object({
        $for(position, [](const Vector2 &pos, int i) {
            return $union({
                $goto(pos),
                label("ㅇ"),
            });
        }),
    });
}
