#include "../framework/main.hpp"

#include <deque>
#include <set>

Scene gameScene();

Object wall(const Property<std::set<std::pair<int, int>>> &position);
Object snake(Property<std::deque<Vector2>> &position);
