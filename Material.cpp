#include "Material.h"

Color Material::computeColor(const Intersection& intersection, const Scene& scene) const {
    // compute diffuse color
    Color color;
    for (auto light:scene.getAllLightSources()) {
        // for each light in the scene, calculate the vector from the intersection
        Vector3 light_vector = light.center - intersection.normal;
        // L.N == |N||L|*cos(angle), and since L and N are normalized below, we can compute the
        // cosine of the angle between the two vectors using the dot product
        double cosine = light_vector.normalized().dot(intersection.normal.normalized());
        // if the angle is more than 90 degrees, it shouldn't affect the result
        if (cosine <= 0) continue;
        color = color + diffuse_color * cosine;
    }
    return color;
}