#pragma once

class Point3;

#include "Point3.h"
#include <cmath>
#include <iostream>

class Vector3 {
    // Avoid expensively renormalizing vectors which have already been normalized
    bool is_normal = false;

    Vector3(float x, float y, float z, bool is_normal_) : coords{x, y, z}, is_normal(is_normal_) { };
public:
    float coords[3];

    Vector3(float x, float y, float z) : coords{x, y, z} { };

    Vector3() { };

    Vector3(const Point3& p1, const Point3& p2);

    Vector3 crossProduct(const Vector3& other) const {
        return Vector3(coords[1] * other.coords[2] - coords[2] * other.coords[1],
                       coords[2] * other.coords[0] - coords[0] * other.coords[2],
                       coords[0] * other.coords[1] - coords[1] * other.coords[0]);
    }

    float dot(const Vector3& other) const {
        return (coords[0] * other.coords[0] + coords[1] * other.coords[1] + coords[2] * other.coords[2]);
    }

    Vector3 operator-() const {
        return Vector3(-coords[0], -coords[1], -coords[2]);
    }

    Vector3 operator/(float factor) const {
        return Vector3(coords[0] / factor, coords[1] / factor, coords[2] / factor);
    }

    Vector3 operator+(const Vector3& other) const {
        return Vector3(coords[0] + other.coords[0], coords[1] + other.coords[1], coords[2] + other.coords[2]);
    }

    Vector3 operator+(const Point3& other) const;

    Vector3 operator-(const Point3& other) const;

    Vector3 operator-(const Vector3& other) const;

    Vector3 operator*(float factor) const {
        return Vector3(coords[0] * factor, coords[1] * factor, coords[2] * factor);
    }

    Vector3 operator*=(float factor) {
        return (*this = operator*(factor));
    }

    Vector3 scaled(float coefficient) const;

    bool isParallel(Vector3& other) {
        float mag = norm(), other_mag = other.norm();
        if ((!mag && other_mag) || (mag && !other_mag))
            return false;
        return coords[0] / mag == other.coords[0] / other_mag && coords[1] / mag == other.coords[1] / other_mag &&
               coords[2] / mag == other.coords[2] / other_mag;
    }

    // some operations only need the squared norm; for performance and precision,
    // use this function instead, avoiding a sqrt followed by a sqr
    float norm_squared() const {
        return coords[0] * coords[0] + coords[1] * coords[1] + coords[2] * coords[2];
    };

    float norm() const {
        return sqrt(norm_squared());
    };

    Vector3 normalized() const {
        if (is_normal) return *this;
        float len = this->norm();
        return Vector3(coords[0] / len, coords[1] / len, coords[2] / len, true);
    };

    void normalize() {
        if (is_normal) return;
        *this = normalized();
        is_normal = true;
    }
};

std::ostream& operator<<(std::ostream& out, const Vector3& vector);
