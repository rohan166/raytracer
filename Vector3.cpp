#include <math.h>
#include <initializer_list>

#include "Vector3.h"

float get_mag(const float* coords) {
    float sum = 0;

    for(auto i : {0, 1, 2}) {
        sum += coords[i]*coords[i];
    }

    return sqrt(sum);
}

Vector3::Vector3(const Point3& p1, const Point3& p2) {
    auto p = (p1 - p2);
    for(auto i : {0, 1, 2}) {
        this->coords[i] = p.coords[i];
    }
}

Vector3 Vector3::scaled(float coefficient) const {
    Vector3 v = *this;
    for(auto i : {0, 1, 2}) {
      v.coords[i] *= coefficient;
    }
    return v;
}

Vector3 Vector3::normalized() const {
    Vector3 v = *this;

    auto mag = get_mag(v.coords);

    for(auto i : {0, 1, 2}) {
        v.coords[i] /= mag;
    }

    return v;
}

