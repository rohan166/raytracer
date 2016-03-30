#include "Sphere.h"

Intersection Sphere::intersects(const Ray& ray) const {
    /*
     * math from https://en.wikipedia.org/wiki/Line%E2%80%93sphere_intersection
     */
    float b = 2 * (ray.d.dot(ray.p - center));
    float c = (ray.p - center).norm_squared() - sqr(radius);
    float bb4ac = sqr(b) - (4 * c);

    if (bb4ac >= 0) {
        float pm = sqrt(bb4ac);
        float t = (-b - pm);
        bool backside = false;
        if (t < EPS) {
            backside = true;
            t = -b + pm;
        }

        if (t >= EPS) {
            // The denominator of the quadratic formula was actually 2,
            // but that didn't matter till now
            t /= 2;
            Point3 p = ray.p + ray.d * t;
            Vector3 n = p - center;
            if (backside) n *= -1;
            // Change this once we have the Material definition
            return Intersection(t, ray, n.normalized(), this);
        }
    }
    return Intersection();
}
