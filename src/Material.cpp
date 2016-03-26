#include "Material.h"

Color Material::computeColor(const Intersection &intersection, const Scene &scene) const {
    Color color;
    for (auto light : scene.getAllLightSources()) {
        // calculate the vector from the intersection to the light
        Vector3 intersection_to_light = (light->origin - intersection.location);
        float dist_to_light = intersection_to_light.norm();
        intersection_to_light.normalize();

        // L.N == |N||L|*cos(angle), and since L and N are normalized below, we can compute the
        // cosine of the angle between the two vectors using the dot product
        float cosine = intersection_to_light.dot(intersection.normal);
        // if the angle is more than 90 degrees, it shouldn't affect the result
        if (cosine <= 0) continue;

        // check if there's an unbroken path to the light - ignore any intersections
        // past the light
        Intersection *occluder = scene.castRay(Ray(intersection.location,
                                                   intersection_to_light),
                                               dist_to_light);
        if (occluder) {
            delete occluder;
            continue;
        }
        color = color + diffuse_color * cosine * light->color;
    }

    color += scene.traceReflection(intersection) * reflectivity;
    return color;
}