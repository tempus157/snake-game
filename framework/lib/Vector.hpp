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
};

#endif
