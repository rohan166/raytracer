#include <math.h>
#include "Vector3.h"

Vector3::Vector3(float x, float y, float z, float m): Triplet(x, y, z), magnitude(m) {}

Vector3::Vector3(Triplet &t, float m): Triplet(t), magnitude(m) {}

Vector3::Vector3(Point &p1, Point &p2) {
    v[0] = p2.first() - p1.first();
    v[1] = p2.second() - p1.second();
    v[2] = p2.third() - p1.third();
    magnitude = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
}

void Vector3::scale(float coefficient) {
    magnitude *= coefficient;
}

Vector3 Vector3::scaled(float coefficient) {
    Vector3 *v = new Vector3(this);
    v->scale(coefficient);;
    return v;
}

void Vector3::normalize() {
    magnitude = 1;
}

Vector3 Vector3::normalized() {
    Vector3 *v = new Vector3(this);
    v->normalize();
    return v;
}

