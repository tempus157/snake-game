#ifndef __FRAMEWORK_VECTOR__
#define __FRAMEWORK_VECTOR__

class Vector final {
public:
    int x = 0;
    int y = 0;

    static const Vector Zero;
    static const Vector One;
    static const Vector Up;
    static const Vector Down;
    static const Vector Left;
    static const Vector Right;

    Vector();
    Vector(int x, int y);
};

#endif
