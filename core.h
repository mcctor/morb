#ifndef H_CORE
#define H_CORE


#include <cmath>
#include <iostream>
#include "util.h"


namespace Morb {

    class Vector3 {
    public:
        Vector3() : x{0}, y{0}, z{0} {
        }

        Vector3(double xx, double yy, double zz) : x{xx}, y{yy}, z{zz} {
        }

        double operator[](int i) const {
            ASSERT(i >= 0 && i <= 2);
            if (i == 0) return x;
            if (i == 1) return y;
            return z;
        }

        double& operator[](int i) {
            ASSERT(i >= 0 && i <= 2);
            if (i == 0) return x;
            if (i == 1) return y;
            return z;
        }

        Vector3 operator+(const Vector3& v) const {
            return Vector3{x+v.x, y+v.y, z+v.z};
        }

        Vector3& operator+=(const Vector3& v) {
            x += v.x; y += v.y; z += v.z;
            return *this;
        }

        Vector3 operator-(const Vector3& v) const {
            return Vector3{x-v.x, y-v.y, z-v.z};
        }

        Vector3& operator-=(const Vector3& v) {
            x -= v.x; y -= v.y; z -= v.z;
            return *this;
        }

        Vector3 operator-() const {
            return Vector3{-x, -y, -z};
        }

        Vector3 operator*(double s) const {
            return Vector3{x * s, y * s, z * s};
        }

        Vector3& operator*=(double s) {
            x *= s; y *= s; z *= s;
            return *this;
        }

        Vector3 operator/(double f) const {
            ASSERT(f != 0);
            double inv = 1.0 / f;
            return Vector3{x * inv, y * inv, z * inv};
        }

        Vector3& operator/=(double f) {
            ASSERT(f != 0);
            double inv = 1.0 / f;
            x *= inv; y *= inv; z *= inv;
            return *this;
        }

    private:

        friend std::ostream& operator<<(std::ostream& os, const Vector3& v);

        friend Vector3 operator*(double s, const Vector3& v);

        double x, y, z;
    };

    std::ostream& operator<<(std::ostream& os, const Vector3& v) {
        return os << "{" << v.x << ", " << v.y << ", " << v.z << "}";
    }

    Vector3 operator*(double s, const Vector3& v) {
        return Vector3{v.x * s, v.y * s, v.z * s};
    }


    class Point3 {

    };

    class Wheel {

    };

    class Sphere {

    };
}


#endif      // H_CORE