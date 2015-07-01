#ifndef RAYTRACER_INTERSECTION_H
#define RAYTRACER_INTERSECTION_H

#include "Color.h"

class Intersection {
    Ray &ray;
    double t; // ray = origin_point + lambda*t
    Vector3 normal;
    Color color;
public:
    Intersection(double t_, Ray& r, Vector3& n, Color &c):
    ray(r), t(t_), normal(n), color(c) {}
    Color getColor() {
        return color;
    }

    Vector3 getNormal() {
        return normal;
    }

    double get_t() {
        return t;
    }

    Ray& getRay() {
        return ray;
    }
};


#endif //RAYTRACER_INTERSECTION_H
