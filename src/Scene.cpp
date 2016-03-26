#include <util.h>
#include "Scene.h"


Intersection *Scene::castRay(Ray ray, float max_t) const {
    // The ray need not be normalized beforehand
    ray.d.normalize();
    Intersection *first_hit = nullptr;
    for (auto prop : propList) {
        Intersection *hit = prop->intersects(ray);
        if (hit &&
            // check that the intersection is ahead of the ray origin,
            hit->t > EPS &&
            // and not beyond max_t
            hit->t < max_t - EPS &&
            // and in front of any previously discovered intersections
            (!first_hit || hit->t < first_hit->t)) {
            first_hit = hit;
        }
    }
    return first_hit;
}