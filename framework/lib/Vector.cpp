#include "Vector.hpp"

const Vector Vector::Zero = Vector(0, 0);
const Vector Vector::One = Vector(1, 1);
const Vector Vector::Up = Vector(0, 1);
const Vector Vector::Down = Vector(0, -1);
const Vector Vector::Left = Vector(-1, 0);
const Vector Vector::Right = Vector(1, 0);

Vector::Vector() {}
Vector::Vector(int x, int y) : x(x), y(y) {}