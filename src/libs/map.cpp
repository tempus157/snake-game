#include "map.hpp"

#include <fstream>
#include <sstream>
#include <string>

bool Map::loadLevel(int level) {
    std::stringstream path;
    path << "src/data/map" << level << ".dat";
    auto stream = std::ifstream(path.str());

    if (stream.fail()) {
        return false;
    }
    parseData(stream);
    return true;
}

void Map::parseData(std::ifstream &stream) {
    auto isHeadFirst = -1;
    std::string buffer;

    for (auto y = 0; std::getline(stream, buffer); y++) {
        for (auto x = 0; x < buffer.length(); x++) {
            auto cell = static_cast<Cell>(buffer[x]);

            if (cell == Cell::None) {
                continue;
            }

            if (cell == Cell::Wall) {
                wall.insert({x * 2, y});
                continue;
            }

            if (cell == Cell::ImmuneWall) {
                immuneWall.insert({x * 2, y});
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
                snake.push_back({x * 2, y});
            } else {
                snake.push_front({x * 2, y});
            }
        }
    }
}
