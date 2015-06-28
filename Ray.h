#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vector3.h"
#include "Point3.h"

class Ray {
    Point3 origin;
    Vector3 direction;

public:
    Ray(const Point3 &origin, const Vector3 &direction) : origin(origin), direction(direction) { }
};


#endif //RAYTRACER_RAY_H
