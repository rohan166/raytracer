#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "Prop.h"
#include "Plane.h"
#include "Vector3.h"
#include "Plane.h"

class Triangle : public Plane {
public:
    Vector3 a;
    Vector3 b;

    Triangle(Point3 &n, Point3 &e, Point3 &f, Material &m) : a(n-e), b(n-f), Plane(m, n, (n-e).crossProduct(n-f)) {
        if (a.isParallel(b))
            throw "points of a triangle can't be collinear";
    };

    Intersection *intersects(const Ray &ray, const Scene &scene) const {
        Intersection *i = Plane::intersects(ray, scene);
        if (i == nullptr) return i;
    }
};


#endif //RAYTRACER_TRIANGLE_H
