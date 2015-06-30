#ifndef PROJECT_VECTOR3_H
#define PROJECT_VECTOR3_H

class Point3;

#include "Point3.h"
#include <cmath>
#include <iostream>

class Vector3 {
public:
    float coords[3];

    Vector3(float x, float y, float z) : coords{x, y, z} { };

    Vector3() { };

    Vector3(const Point3 &p1, const Point3 &p2);

    Vector3 crossProduct(const Vector3 &other) const {
        return Vector3(coords[1] * other.coords[2] - coords[2] * other.coords[1],
                       coords[2] * other.coords[0] - coords[0] * other.coords[2],
                       coords[0] * other.coords[1] - coords[1] * other.coords[0]);
    }

    Vector3 dot(const Vector3 &other) const {
        return Vector3(coords[1] * other.coords[2] - coords[2] * other.coords[1],
                       coords[2] * other.coords[0] - coords[0] * other.coords[2],
                       coords[0] * other.coords[1] - coords[1] * other.coords[0]);
    }

    Vector3 operator-() const {
        return Vector3(-coords[0], -coords[1], -coords[2]);
    }

    Vector3 operator/(double factor) const {
        return Vector3(coords[0] / factor, coords[1] / factor, coords[2] / factor);
    }

    Vector3 operator*(double factor) const {
        return Vector3(coords[0] * factor, coords[1] * factor, coords[2] * factor);
    }

    Vector3 operator*=(double factor) {
        return (*this = operator*(factor));
    }

    Vector3 scaled(float coefficient) const;

    Vector3 scaled(double coefficient) const;

    double norm_squared() const {
        return coords[0] * coords[0] + coords[1] * coords[1] + coords[2] * coords[2];
    };

    double norm() const {
        return sqrt(norm_squared());
    };

    Vector3 normalized() const {
        double len = this->norm();
        return Vector3(coords[0] / len, coords[1] / len, coords[2] / len);
    };

    void normalize() {
        *this = normalized();
    }
};

std::ostream &operator<<(std::ostream &out, const Vector3 &vector);

#endif //PROJECT_VECTOR3_H
