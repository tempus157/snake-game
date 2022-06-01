#include "../main.hpp"

#include "../libs/map.hpp"
#include <deque>
#include <set>

Scene gameScene() {
    auto immuneWallPosition = Property<std::set<std::pair<int, int>>>();
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

            if (cell == Cell::ImmuneWall) {
                immuneWallPosition->insert({x * 2, y});
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
        $goto(Vector2(30, 0)),
        wall(wallPosition, immuneWallPosition),
        $goto(Vector2(30, 0)),
        snake(snakePosition, wallPosition),
        $goto(Vector2(30, 0)),
        logger(snakePosition),
    });
}
