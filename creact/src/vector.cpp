#include "vector.h"

namespace Creact {
    const Vector Vector::Zero = Vector(0, 0);
    const Vector Vector::One = Vector(1, 1);
    const Vector Vector::Up = Vector(0, -1);
    const Vector Vector::Down = Vector(0, 1);
    const Vector Vector::Left = Vector(-1, 0);
    const Vector Vector::Right = Vector(1, 0);

    Vector::Vector() {}
    Vector::Vector(int x, int y) : x(x), y(y) {}

    Vector Vector::operator+(const Vector &other) const {
        return Vector(x + other.x, y + other.y);
    }

    Vector &Vector::operator+=(const Vector &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector Vector::operator-(const Vector &other) const {
        return Vector(x - other.x, y - other.y);
    }

    Vector &Vector::operator-=(const Vector &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector Vector::operator-() const {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(int scalar) const {
        return Vector(x * scalar, y * scalar);
    }

    Vector &Vector::operator*=(int scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector Vector::operator/(int scalar) const {
        return Vector(x / scalar, y / scalar);
    }

    Vector &Vector::operator/=(int scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    bool Vector::operator==(const Vector &other) const {
        return x == other.x && y == other.y;
    }

    bool Vector::operator!=(const Vector &other) const {
        return x != other.x || y != other.y;
    }
}
