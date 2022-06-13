#ifndef __MAP__
#define __MAP__

#include "../../framework/main.hpp"

#include <deque>
#include <set>

enum class Cell : char {
    None = ' ',
    Wall = '#',
    ImmuneWall = '@',
    SnakeHead = '+',
    SnakeBody = '=',
};

class Map final {
public:
    std::set<std::pair<int, int>> wall;
    std::set<std::pair<int, int>> immuneWall;
    std::deque<Vector2> snake;

    bool loadLevel(int level);

private:
    void parseData(std::ifstream &stream);
};

#endif
