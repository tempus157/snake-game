#include "../framework/main.hpp"
#include <deque>

Scene gameScene();

Object wall();
Object snake(Property<std::deque<Vector2>> &position);
