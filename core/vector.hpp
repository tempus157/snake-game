#ifndef __CORE_VECTOR__
#define __CORE_VECTOR__

struct Vector
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