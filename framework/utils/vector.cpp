#include "vector.hpp"

const Vector Vector::zero = Vector(0, 0);
const Vector Vector::one = Vector(1, 1);
const Vector Vector::up = Vector(0, 1);
const Vector Vector::down = Vector(0, -1);
const Vector Vector::left = Vector(-1, 0);
const Vector Vector::right = Vector(1, 0);

Vector::Vector() {}
Vector::Vector(int x, int y) : x(x), y(y) {}