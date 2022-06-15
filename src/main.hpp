#include "../framework/main.hpp"

#include <deque>
#include <set>

Scene introScene();
Scene gameScene();
Scene resultScene();

Object wall(const Property<std::set<std::pair<int, int>>> &position,
    const Property<std::set<std::pair<int, int>>> &immunePosition);

Object snake(Property<std::deque<Vector2>> &position,
    const Property<std::set<std::pair<int, int>>> &wallPosition);
