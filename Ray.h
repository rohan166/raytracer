#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H

#include "Vector3.h"
#include "Point3.h"

class Ray {
public:
    Point3 origin;
    Vector3 direction;

    Ray(const Point3& origin, const Vector3& direction) : origin(origin), direction(direction) { }
};


#endif //RAYTRACER_RAY_H
