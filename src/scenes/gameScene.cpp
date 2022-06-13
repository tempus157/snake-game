#include "../main.hpp"

#include <fstream>
#include <sstream>

bool parseData(const std::function<void(char, int, int)> &callback) {
    std::stringstream path;
    path << "src/data/map0.dat";
    auto stream = std::ifstream(path.str());

    if (stream.fail()) {
        return false;
    }

    std::string buffer;
    for (auto y = 0; std::getline(stream, buffer); y++) {
        for (auto x = 0; x < buffer.length(); x++) {
            callback(buffer[x], x, y);
        }
    }

    return true;
}

Scene gameScene() {
    auto wallPosition = Property<std::set<std::pair<int, int>>>();
    auto immuneWallPosition = Property<std::set<std::pair<int, int>>>();
    auto snakePosition = Property<std::deque<Vector2>>();
    auto isHeadFirst = -1;

    auto success = parseData([=](char cell, int x, int y) mutable {
        switch (cell) {
        case '#':
            wallPosition->insert({x * 2, y});
            break;
        case '@':
            immuneWallPosition->insert({x * 2, y});
            break;
        case '+':
            snakePosition->push_back({x * 2, y});
            if (snakePosition->size() != 0) {
                std::reverse(snakePosition->begin(), snakePosition->end());
            }
            break;
        case '=':
            snakePosition->push_back({x * 2, y});
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
