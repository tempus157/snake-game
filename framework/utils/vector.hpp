#ifndef __FRAMEWORK_UTILS_VECTOR__
#define __FRAMEWORK_UTILS_VECTOR__

class Vector
{
public:
    int x = 0;
    int y = 0;

    static const Vector zero;
    static const Vector one;
    static const Vector up;
    static const Vector down;
    static const Vector left;
    static const Vector right;

    Vector();
    Vector(int x, int y);
};

#endif
