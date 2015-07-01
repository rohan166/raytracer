#ifndef RAYTRACER_PLANE_H
#define RAYTRACER_PLANE_H

#include <Intersection.h>

class Plane {
public:
    Point3 p;  // any point on the plane
    Vector3 n; // the normal vector of the plane
    Plane() { }

    Plane(Point3 &p, Vector3 &n) : p(p), n(n) { }

    Intersection *intersects(const Ray &ray) const {
        // if the ray is parallel to the plane, it never intersects
        if (n.dot(ray.d) == 0.0) return nullptr;

        // math happens here
        double t = n.dot(p - ray.p) / n.dot(ray.d);

        // pending implementation of Intersection constructor
        // normal vector is simply this->n
        // t is as computed above
        return Intersection;
    }
};


#endif //RAYTRACER_PLANE_H
