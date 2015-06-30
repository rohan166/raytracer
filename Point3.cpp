#include "Point3.h"
#include <initializer_list>
#include <iostream>

Vector3 Point3::operator-(const Point3 &other) const {
    return Vector3(*this, other);
}

Point3 Point3::operator+(const Vector3 &other) const {
    Point3 p = *this;

    for (auto i : {0, 1, 2}) {
        p.coords[i] += other.coords[i];
    }

    return p;
}

Point3 Point3::operator-(const Vector3 &other) const {
    return *this + (-other);
}

std::ostream &operator<<(std::ostream &out, const Point3 &point) {
    out << "(" << point.coords[0] << ", " << point.coords[1] << ", " << point.coords[2] << ")";
    return out;
}