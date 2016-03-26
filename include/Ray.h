#pragma once

#include "Vector3.h"
#include "Point3.h"

class Ray {
public:
    Point3 p;
    Vector3 d;

    Ray(const Point3 &p_, const Vector3 &d_) : p(p_), d(d_) { }

    Ray(const Point3 &from, const Point3 &to) : p(from), d(to - from) { }

    Ray() { }
};

std::ostream &operator<<(std::ostream &out, const Ray &ray);