#pragma once

#include "Color.h"
#include "Ray.h"
#include "Vector3.h"
#include <cassert>

class Prop;

class Intersection {
public:
    Ray incidentRay;
    Ray reflectedRay;
    float t; // ray = origin_point + lambda*t
    int depth = 0;
    Vector3 normal;
    Point3 location;
    float cur_ri = 1;
    const Prop* prop;

    Intersection() { prop = nullptr; };
    Intersection(double t, Ray r, Vector3 n, const Prop* p);

    Vector3 getReflected() const {
        return (incidentRay.d - normal * 2 * incidentRay.d.dot(normal)).normalized();
    }

    Vector3 getV() const {
        return -incidentRay.d.normalized();
    }

    float getNdotV() const {
        return -normal.dot(incidentRay.d.normalized());
    }

    Ray getRefracted(float new_ri) const {
        float n = cur_ri / new_ri;
        float c1 = getNdotV();
        float cs2 = 1 - n * n * (1 - c1 * c1);
        assert(cs2 >= 0);
        Vector3 refracted = normal * (c1 * n - sqrt(cs2)) - getV() * n;
        return Ray(location, refracted);
    }
};
