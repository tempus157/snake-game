#include "../main.hpp"

#include "../libs/map.hpp"
#include <deque>
#include <set>

Scene gameScene() {
    auto wallPosition = Property<std::set<std::pair<int, int>>>();
    auto snakePosition = Property<std::deque<Vector2>>();

    // TODO Refactor this shit
    int isHeadFirst = -1;
    for (auto y = 0; y < map.size(); y++) {
        for (auto x = 0; x < map[y].size(); x++) {
            const auto cell = static_cast<Cell>(map[y][x]);
            if (cell == Cell::None) {
                continue;
            }

            if (cell == Cell::Wall) {
                wallPosition->insert({x * 2, y});
                continue;
            }

            if (isHeadFirst == -1) {
                if (cell == Cell::SnakeHead) {
                    isHeadFirst = 1;
                } else if (cell == Cell::SnakeBody) {
                    isHeadFirst = 0;
                }
            }

            if (isHeadFirst) {
                snakePosition->push_back({x * 2, y});
            } else {
                snakePosition->push_front({x * 2, y});
            }
        }
    }

    return Object({
        wall(wallPosition),
        snake(snakePosition),

        // Snake position log
        $for(snakePosition, [](const Vector2 &pos, int i) {
            return $union({
                $goto(Vector2(2, i + 1)),
                label(std::to_string(pos.x) + "," + std::to_string(pos.y)),
            });
        }),
    });
}
