#ifndef RAYTRACER_INTERSECTION_H
#define RAYTRACER_INTERSECTION_H

#include "Color.h"
#include "Ray.h"
#include "Prop.h"
#include "Vector3.h"

class Prop;

class Intersection {
public:
    Ray &incidentRay;
    Ray reflectedRay;
    double t; // ray = origin_point + lambda*t
    int depth = 0;
    Vector3 normal;
    Point3 location;
    const Prop &prop;

    Intersection(double t, Ray r, Vector3 n, const Prop &p);
};


#endif //RAYTRACER_INTERSECTION_H
