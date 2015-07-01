#ifndef RAYTRACER_INTERSECTION_H
#define RAYTRACER_INTERSECTION_H

#include "Color.h"
#include "Ray.h"
#include "Vector3.h"

class Intersection {
public:
    Ray &ray;
    double t; // ray = origin_point + lambda*t
    Vector3 normal;
    Color color;
    Intersection(double t_, Ray& r, Vector3& n, Color &c):
                ray(r), t(t_), normal(n), color(c) {}
};


#endif //RAYTRACER_INTERSECTION_H
