#ifndef __CREACT_VECTOR__
#define __CREACT_VECTOR__

namespace Creact {
    class Vector final {
    public:
        int x;
        int y;

        static const Vector Zero;
        static const Vector One;
        static const Vector Up;
        static const Vector Down;
        static const Vector Left;
        static const Vector Right;

        Vector();
        Vector(int x, int y);

        Vector operator+(const Vector &other) const;
        Vector &operator+=(const Vector &other);
        Vector operator-(const Vector &other) const;
        Vector &operator-=(const Vector &other);
        Vector operator-() const;

        Vector operator*(int scalar) const;
        Vector &operator*=(int scalar);
        Vector operator/(int scalar) const;
        Vector &operator/=(int scalar);

        bool operator==(const Vector &other) const;
        bool operator!=(const Vector &other) const;
    };
}

#endif
