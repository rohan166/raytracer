#include <util.h>
#include "Plane.h"

class Intersection;

Intersection *Plane::intersects(const Ray &ray) const {
    // if the ray is parallel to the plane, it never intersects
    float denom = n.dot(ray.d);
    if (denom == 0.0) return nullptr;

    // math happens here
    float t = n.dot(p - ray.p) / denom;
    if (t < EPS) return nullptr;

    float cosine = (-n).dot(ray.d);
    // If we hit the "back" side of the plane, negate the normal vector
    if (cosine < 0)
        return new Intersection(t, ray, -n, *this);
    else
        return new Intersection(t, ray, n, *this);

    // pending implementation of Intersection constructor
    // normal vector is simply this->n
    // t is as computed above

}
