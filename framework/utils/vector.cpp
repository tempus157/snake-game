#include "vector.hpp"

const Vector Vector::Zero = {0, 0};
const Vector Vector::One = {1, 1};
const Vector Vector::Up = {0, 1};
const Vector Vector::Down = {0, -1};
const Vector Vector::Left = {-1, 0};
const Vector Vector::Right = {1, 0};

Vector::Vector() {}
Vector::Vector(int x, int y) : x(x), y(y) {}