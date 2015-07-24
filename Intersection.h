#ifndef RAYTRACER_INTERSECTION_H
#define RAYTRACER_INTERSECTION_H

#include "Color.h"
#include "Ray.h"
#include "Prop.h"
#include "Vector3.h"

class Intersection {
public:
    const Ray& ray;
    double t; // ray = origin_point + lambda*t
    Vector3 normal;
    Point3 location;
    const Prop& prop;

    Intersection(double t, const Ray& r, Vector3 n, const Prop& prop) : ray(r), t(t), normal(n), prop(prop) { }
};


#endif //RAYTRACER_INTERSECTION_H
