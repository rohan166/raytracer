#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vector3.h"
#include "Point3.h"

class Ray {
public:
    Point3 p;
    Vector3 d;

    Ray(const Point3 &p_, const Vector3 &d_) : p(p_), d(d_) { }
};

std::ostream &operator<<(std::ostream &out, const Ray &ray);

#endif //RAYTRACER_RAY_H
