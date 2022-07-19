#ifndef __FRAMEWORK_VECTOR__
#define __FRAMEWORK_VECTOR__

class Vector2 final {
public:
    int x = 0;
    int y = 0;

    static const Vector2 Zero;
    static const Vector2 One;
    static const Vector2 Up;
    static const Vector2 Down;
    static const Vector2 Left;
    static const Vector2 Right;

    Vector2();
    Vector2(int x, int y);

    Vector2 operator+(const Vector2 &other) const;
    Vector2 &operator+=(const Vector2 &other);
    Vector2 operator-(const Vector2 &other) const;
    Vector2 &operator-=(const Vector2 &other);
    Vector2 operator-() const;

    Vector2 operator*(int scalar) const;
    Vector2 &operator*=(int scalar);
    Vector2 operator/(int scalar) const;
    Vector2 &operator/=(int scalar);

    bool operator==(const Vector2 &other) const;
    bool operator!=(const Vector2 &other) const;
};

#endif
