#ifndef __CORE_VECTOR__
#define __CORE_VECTOR__

struct Vector
{
public:
    int x = 0;
    int y = 0;

    static Vector zero;
    static Vector one;
    static Vector up;
    static Vector down;
    static Vector left;
    static Vector right;

    Vector();
    Vector(int x, int y);
};

#endif