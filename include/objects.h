#ifndef __SNAKE_GAME_OBJECT__
#define __SNAKE_GAME_OBJECT__

#include "../creact/main.hpp"

#include <deque>
#include <set>

Object wall(const Property<std::set<std::pair<int, int>>> &position,
    const Property<std::set<std::pair<int, int>>> &immunePosition);

Object snake(Property<std::deque<Vector2>> &position,
    const Property<std::set<std::pair<int, int>>> &wallPosition);

#endif