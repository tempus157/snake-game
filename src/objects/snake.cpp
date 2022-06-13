#include "../main.hpp"

#include <algorithm>
#include <queue>

Object snake(Property<Map> &map) {
    auto direction = Property<Vector2>(Vector2::Right * 2);

    asyncLoop(100, [=]() mutable {
        soundBeep();
        const auto newPosition = map->snake.front() + *direction;
        if (std::count(map->snake.begin(), map->snake.end(), newPosition) >= 1) {
            changeScene("result");
        }
        if (map->wall.count({newPosition.x, newPosition.y}) >= 1) {
            changeScene("result");
        }

        map->snake.pop_back();
        map->snake.push_front(newPosition);
        map.set(*map);
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
        $for(map->snake, [](const Vector2 &pos, int i) {
            return $union({
                $goto(pos),
                $if(i == 0,
                    label("ㅎ", Color::Yellow, Color::Black),
                    label("ㅇ", Color::Yellow, Color::Black)),
            });
        }),
    });
}
