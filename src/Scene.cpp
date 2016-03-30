#include <util.h>
#include "Scene.h"


Intersection Scene::castRay(Ray ray, float max_t) const {
    // The ray need not be normalized beforehand
    ray.d.normalize();
    Intersection first_hit;
    for (auto prop : propList) {
        Intersection hit = prop->intersects(ray);
        if (hit.prop &&
            // check that the intersection is ahead of the ray origin,
            hit.t > EPS &&
            // and not beyond max_t
            hit.t < max_t - EPS &&
            // and in front of any previously discovered intersections
            (!first_hit.prop || hit.t < first_hit.t)) {
            first_hit = hit;
        }
    }
    return first_hit;
}

Color Scene::traceRay(Ray ray, int depth, float ri, float* dist) const {
    if (depth > 5) return backgroundColor;
    Intersection intersection = castRay(ray);
    Color result;
    // TODO: hack to clip scene at z=0; need to implement rectangles
    if (!intersection.prop || intersection.location.coords[2] > 0) {
        result = backgroundColor;
        if (dist) *dist = 0;
    }
    else {
        intersection.depth = depth;
        intersection.cur_ri = ri;
        if (dist) *dist = intersection.t * ray.d.norm();
        result = intersection.prop->material.computeColor(intersection, *this);
    }
    return result;
}