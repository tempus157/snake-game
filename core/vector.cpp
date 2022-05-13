#include "vector.hpp"

Vector Vector::zero = Vector(0, 0);
Vector Vector::one = Vector(1, 1);
Vector Vector::up = Vector(0, 1);
Vector Vector::down = Vector(0, -1);
Vector Vector::left = Vector(-1, 0);
Vector Vector::right = Vector(1, 0);

Vector::Vector() {}
Vector::Vector(int x, int y) : x(x), y(y) {}