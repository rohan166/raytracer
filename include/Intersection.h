#pragma once

#include "Color.h"
#include "Ray.h"
#include "Vector3.h"

class Prop;

class Intersection {
public:
    Ray incidentRay;
    Ray reflectedRay;
    double t; // ray = origin_point + lambda*t
    int depth = 0;
    Vector3 normal;
    Point3 location;
    const Prop* prop;

    Intersection() { prop = nullptr; };
    Intersection(double t, Ray r, Vector3 n, const Prop* p);

    Vector3 getReflected() const {
        return (incidentRay.d - normal * 2 * incidentRay.d.dot(normal)).normalized();
    }
};