#include "../main.hpp"

#include <fstream>
#include <sstream>

enum class Cell : char {
    Wall = '#',
    ImmuneWall = '@',
    SnakeHead = '+',
    SnakeBody = '=',
};

bool parseData(const std::function<void(const Cell &, int, int)> &callback) {
    std::stringstream path;
    path << "src/data/map0.dat";
    auto stream = std::ifstream(path.str());

    if (stream.fail()) {
        return false;
    }

    auto isHeadFirst = -1;
    std::string buffer;

    for (auto y = 0; std::getline(stream, buffer); y++) {
        for (auto x = 0; x < buffer.length(); x++) {
            auto cell = static_cast<Cell>(buffer[x]);
            callback(cell, x, y);
        }
    }

    return true;
}

Scene gameScene() {
    auto wallPosition = Property<std::set<std::pair<int, int>>>();
    auto immuneWallPosition = Property<std::set<std::pair<int, int>>>();
    auto snakePosition = Property<std::deque<Vector2>>();
    auto isHeadFirst = -1;

    auto success = parseData([=](const Cell &cell, int x, int y) mutable {
        switch (cell) {
        case Cell::Wall:
            wallPosition->insert({x * 2, y});
            break;
        case Cell::ImmuneWall:
            immuneWallPosition->insert({x * 2, y});
            break;
        case Cell::SnakeHead:
            if (isHeadFirst == -1) {
                isHeadFirst = 1;
            }
        case Cell::SnakeBody:
            if (isHeadFirst == -1) {
                isHeadFirst = 0;
            }

            if (isHeadFirst) {
                snakePosition->push_back({x * 2, y});
            } else {
                snakePosition->push_front({x * 2, y});
            }
            break;
        default:
            break;
        }
    });

    if (!success) {
        quitApp();
    }

    return Object({
        $goto(Vector2(30, 0)),
        wall(wallPosition, immuneWallPosition),
        $goto(Vector2(30, 0)),
        snake(snakePosition, wallPosition),
    });
}
