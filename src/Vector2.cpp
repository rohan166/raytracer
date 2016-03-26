#include "Vector2.h"
#include "util.h"
#include <math.h>


Vector2::Vector2(const Point2 &p1, const Point2 &p2) {
    coords[0] = p2.coords[0] - p1.coords[0];
    coords[1] = p2.coords[1] - p1.coords[1];
}

void Vector2::scale(float coefficient) {
    coords[0] *= coefficient;
    coords[1] *= coefficient;
}

Vector2 Vector2::scaled(float coefficient) const {
    Vector2 v = *this;
    v.scale(coefficient);
    return v;
}

double Vector2::norm_squared() const {
    return sqr(coords[0]) + sqr(coords[1]);
}

double Vector2::norm() const {
    return sqrt(norm_squared());
}

Vector2 Vector2::normalized() const {
    Vector2 v = *this;
    double len = v.norm();
    return Vector2(coords[0] / len, coords[1] / len);
}
