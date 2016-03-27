#include "Material.h"
#include "Scene.h"

Color Material::computeColor(const Intersection& intersection, const Scene& scene) const {
    Color color;

    // direction from intersection to viewer
    Vector3 V = -intersection.incidentRay.d.normalized();

    if (kref != 0) {
        float R = pow((1 - ri) / (1 + ri), 2);
        R = R + (1 - R) * pow(1 - intersection.normal.dot(V), 5);
        R *= kref;

        Ray reflectedRay(intersection.location, intersection.getReflected());
        color += scene.traceRay(reflectedRay, intersection.depth + 1) * R;
    }


    for (auto light : scene.getAllLightSources()) {
        // calculate the vector from the intersection to the light
        Vector3 L = (light->origin - intersection.location);
        float dist_to_light = L.norm();
        L.normalize();

        // L.N == |N||L|*cos(angle), and since L and N are normalized below, we can compute the
        // cosine of the angle between the two vectors using the dot product
        float cosine = L.dot(intersection.normal);
        // if the angle is more than 90 degrees, it shouldn't affect the result
        if (cosine <= 0) continue;

        // check if there's an unbroken path to the light - ignore any intersections
        // past the light
        Intersection occluder = scene.castRay(Ray(intersection.location, L), dist_to_light);
        if (occluder.prop) continue;

        if (kspec != 0) {
            // halfway vector
            Vector3 H = (L + V).normalized();
            Color spec = light->color * kspec * pow(intersection.normal.dot(H), 25);
            color = color + spec;
            if (ktrans != 0) {
                // TODO: compute transmission
            }
        }

        color = color + base * (1 - kref - kspec - ktrans) * cosine * light->color;
    }

    return color;
}
