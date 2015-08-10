#include "Plane.h"
#include "Intersection.h"

class Intersection;

Intersection* Plane::intersects(const Ray& ray) const {
    // if the ray is parallel to the plane, it never intersects
    if (n.dot(ray.d) == 0.0) return nullptr;

    // math happens here
    double t = n.dot(p - ray.p) / n.dot(ray.d);

    // pending implementation of Intersection constructor
    // normal vector is simply this->n
    // t is as computed above
    return new Intersection(t, ray, n, *this);
}
