#include <util.h>
#include "Scene.h"
#include "Material.h"


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
            if(first_hit) delete first_hit;
            first_hit = hit;
        } else {
            delete hit;
        }
    }
    return first_hit;
}

Color Scene::traceRay(Ray ray, int depth) const {
    if(depth > 3) return backgroundColor;
    Intersection *intersection = castRay(ray);
    Color result;
    // TODO: hack to clip scene at z=0; need to implement rectangles
    if (!intersection || intersection->location.coords[2] > 0) {
        result = backgroundColor;
    } else {
        intersection->depth = depth;
        result = intersection->prop.material.computeColor(*intersection, *this);
    }
    delete intersection;
    return result;
}