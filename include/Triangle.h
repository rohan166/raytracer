#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "Prop.h"
#include "Intersection.h"
#include "Plane.h"
#include "Vector3.h"
#include "Plane.h"

class Intersection;

class Triangle : public Plane {
public:
    Vector3 a, b;

    Triangle(Point3 &n, Point3 &e, Point3 &f, Material &m);

    Intersection *intersects(const Ray &ray) const;
};


#endif //RAYTRACER_TRIANGLE_H
