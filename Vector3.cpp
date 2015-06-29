#include <math.h>
#include <initializer_list>

#include "Vector3.h"

float get_mag(const float* coords) {
    float sum = 0;

    for (auto i : {0, 1, 2}) {
        sum += coords[i] * coords[i];
    }

    return sqrt(sum);
}

Vector3::Vector3(const Point3& p1, const Point3& p2) : coords{p2.coords[0] - p1.coords[0], p2.coords[1] - p1.coords[1],
                                                              p2.coords[2] - p1.coords[2]} {
}

Vector3 Vector3::scaled(float coefficient) const {
    Vector3 v = *this;
    for (auto i : {0, 1, 2}) {
        v.coords[i] *= coefficient;
    }
    return v;
}