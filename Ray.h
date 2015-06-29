#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vector3.h"
#include "Point3.h"

class Ray {
    Point3 p;
    Vector3 d;

public:
    Ray(const Point3 &p_, const Vector3 &d_) : p(p_), d(d_) { }
};


#endif //RAYTRACER_RAY_H
