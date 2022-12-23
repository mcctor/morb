#ifndef H_CORE
#define H_CORE


#include <cmath>
#include <initializer_list>
#include <iostream>
#include <vector>

#include "util.h"


namespace Morb {

    class Vector3 {
    public:
    
        Vector3() : x{0}, y{0}, z{0} {
        }

        Vector3(double xx, double yy, double zz) : x{xx}, y{yy}, z{zz} {
        }

        double length_squared() const {
            return x * x + y * y + z * z;
        }

        double length() const {
            return std::sqrt(length_squared());
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

    inline std::ostream& operator<<(std::ostream& os, const Vector3& v) {
        return os << "{" << v.x << ", " << v.y << ", " << v.z << "}";
    }

    inline Vector3 operator*(double s, const Vector3& v) {
        return Vector3{v.x * s, v.y * s, v.z * s};
    }

    inline double dot(const Vector3& u, const Vector3& v) {
        return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
    }


    class Point3 {
    public:
        Point3() : x{0.0}, y{0.0}, z{0.0} {
        }

        Point3(double xx, double yy, double zz) : x{xx}, y{yy}, z{zz} {
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

        Point3 operator+(const Vector3& v) const {
            return Point3{x + v[0], y + v[1], z + v[2]};
        }

        Point3& operator+=(const Vector3& v) {
            x += v[0]; y += v[1]; z += v[2];
            return *this;
        }

        Vector3 operator-(const Point3& p) const {
            return Vector3{x - p.x, y - p.y, z - p.z};
        }

        Point3 operator-(const Vector3& v) const {
            return Point3{x - v[0], y - v[1], z - v[2]};
        }


    private:

        double x, y, z;
    };


    class Wheel {
    public:

        class Value {};

        Wheel(int seg_num) {
            ASSERT(seg_num >= 0);
            segments.resize(seg_num);
        }

        Wheel(std::initializer_list<Value> seg_list) {
            segments = std::vector<Value>{seg_list};
        }

        Value operator[](int i) const {
            ASSERT(i >= 0 && i < segments.size());
            return segments.at(i);
        }

        Value& operator[](int i) {
            ASSERT(i >= 0 && i < segments.size());
            return segments.at(i);
        }


    private:

        Point3 centre;
        Vector3 orientation;
        std::vector<Value> segments;
    };


    class Sphere {

    };
}


#endif      // H_CORE