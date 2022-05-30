#include "Vector.hpp"

const Vector2 Vector2::Zero = Vector2(0, 0);
const Vector2 Vector2::One = Vector2(1, 1);
const Vector2 Vector2::Up = Vector2(0, 1);
const Vector2 Vector2::Down = Vector2(0, -1);
const Vector2 Vector2::Left = Vector2(-1, 0);
const Vector2 Vector2::Right = Vector2(1, 0);

Vector2::Vector2() {}
Vector2::Vector2(int x, int y) : x(x), y(y) {}