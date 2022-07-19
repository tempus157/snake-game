#include "Vector.hpp"

const Vector2 Vector2::Zero = Vector2(0, 0);
const Vector2 Vector2::One = Vector2(1, 1);
const Vector2 Vector2::Up = Vector2(0, -1);
const Vector2 Vector2::Down = Vector2(0, 1);
const Vector2 Vector2::Left = Vector2(-1, 0);
const Vector2 Vector2::Right = Vector2(1, 0);

Vector2::Vector2() {}
Vector2::Vector2(int x, int y) : x(x), y(y) {}

Vector2 Vector2::operator+(const Vector2 &other) const {
    return Vector2(x + other.x, y + other.y);
}

Vector2 &Vector2::operator+=(const Vector2 &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2 Vector2::operator-(const Vector2 &other) const {
    return Vector2(x - other.x, y - other.y);
}

Vector2 &Vector2::operator-=(const Vector2 &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2 Vector2::operator-() const {
    return Vector2(-x, -y);
}

Vector2 Vector2::operator*(int scalar) const {
    return Vector2(x * scalar, y * scalar);
}

Vector2 &Vector2::operator*=(int scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2 Vector2::operator/(int scalar) const {
    return Vector2(x / scalar, y / scalar);
}

Vector2 &Vector2::operator/=(int scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

bool Vector2::operator==(const Vector2 &other) const {
    return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2 &other) const {
    return x != other.x || y != other.y;
}
