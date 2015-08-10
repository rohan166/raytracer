#include "Scene.h"
#include "Camera.h"


Intersection* Scene::castRay (Ray ray) {
    Intersection *first_hit = nullptr;
    for (auto prop : propList) {
        Intersection *hit = prop->intersects(ray);
        if (hit && (!first_hit || hit->location.distanceFrom(ray.p) < first_hit->location.distanceFrom(ray.p))) {
            first_hit = hit;
        }
    }
    return first_hit;
}