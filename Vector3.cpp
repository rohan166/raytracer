#include <cmath>
#include <initializer_list>

#include <iostream>
#include "Vector3.h"

Vector3::Vector3(const Point3 &p1, const Point3 &p2) : coords{p2.coords[0] - p1.coords[0],
                                                              p2.coords[1] - p1.coords[1],
                                                              p2.coords[2] - p1.coords[2]} {
}

Vector3 Vector3::scaled(float coefficient) const {
    Vector3 v = *this;
    for (auto i : {0, 1, 2}) {
        v.coords[i] *= coefficient;
    }
    return v;
}


std::ostream &operator<<(std::ostream &out, const Vector3 &vector) {
    out << "<" << vector.coords[0] << ", " << vector.coords[1] << ", " << vector.coords[2] << ">";
    return out;
}