#include "../main.hpp"

#include <queue>

Object snake() {
    auto direction = Property<Vector2>(Vector2::Right * 2);
    auto position = Property<std::deque<Vector2>>({
        Vector2(4, 0),
        Vector2(2, 0),
        Vector2(0, 0),
    });

    asyncLoop(100, [=]() mutable {
        auto head = position->front();
        position->pop_back();
        position->push_front(head + *direction);
        position.set(*position);
    });

    onKeyPress(Key::UpArrow, [=]() mutable {
        if (*direction == Vector2::Down) {
            quitApp();
        }
        direction.set(Vector2::Up);
    });

    onKeyPress(Key::DownArrow, [=]() mutable {
        if (*direction == Vector2::Up) {
            quitApp();
        }
        direction.set(Vector2::Down);
    });

    onKeyPress(Key::LeftArrow, [=]() mutable {
        if (*direction == Vector2::Right * 2) {
            quitApp();
        }
        direction.set(Vector2::Left * 2);
    });

    onKeyPress(Key::RightArrow, [=]() mutable {
        if (*direction == Vector2::Left * 2) {
            quitApp();
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
