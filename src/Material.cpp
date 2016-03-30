#include "Material.h"
#include "Scene.h"

Color Material::computeColor(const Intersection& intersection, const Scene& scene) const {
    Color color;

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

        color += computeColor(intersection, *light);
    }

    return color;
}


Color Diffuse::computeColor(const Intersection& intersection, const Light& light) const {
    // calculate the vector from the intersection to the light
    Vector3 L = (light.origin - intersection.location).normalized();
    return base * intersection.normal.dot(L) * light.color;
}

Color reflectedColor(const Intersection& intersection, const Scene& scene) {
    Ray reflectedRay(intersection.location, intersection.getReflected());
    return scene.traceRay(reflectedRay, intersection.depth + 1);
}

Color Metal::computeColor(const Intersection& intersection, const Scene& scene) const {
    return reflectedColor(intersection, scene) * base;
}


Color Shiny::computeColor(const Intersection& intersection, const Scene& scene) const {
    Color color;

    // compute reflected color
    if (kref != 0) {

        // direction from intersection to viewer
        Vector3 V = -intersection.incidentRay.d.normalized();

        float R = 0.6;
        R = R + (1 - R) * pow(1 - intersection.normal.dot(V), 5);
        R *= kref;

        color += reflectedColor(intersection, scene) * R;
    }

    return color + Material::computeColor(intersection, scene) * (1 - kref);
}

Color Shiny::computeColor(const Intersection& intersection, const Light& light) const {
    Color color;

    if (kspec != 0) {
        // direction from intersection to light
        Vector3 L = (light.origin - intersection.location);

        // halfway vector
        Vector3 H = (L + intersection.getV()).normalized();
        color = color + light.color * kspec * pow(intersection.normal.dot(H), phong_exp);
    }

    return color + Diffuse::computeColor(intersection, light) * (1 - kspec);
}


Color Glass::computeColor(const Intersection& intersection, const Scene& scene) const {
    Color result;
    float R = pow((intersection.cur_ri - ri) / (intersection.cur_ri + ri), 2);
    R = R + (1 - R) * pow(1 - intersection.getNdotV(), 5);
    float n, new_ri;
    // are we exiting the medium?
    if (intersection.cur_ri == ri) {
        // TODO: for now we just assume we always exit into vacuum
        new_ri = 1;
    }
    else {
        new_ri = ri;
    }

    n = intersection.cur_ri / new_ri;

    float c1 = intersection.getNdotV();
    float cs2 = 1 - n * n * (1 - c1 * c1);
    if (cs2 >= 0) {
        Vector3 refracted = intersection.normal * (c1 * n - sqrt(cs2)) - intersection.getV() * n;
        Ray refractedRay(intersection.location, refracted);
        float dist;
        Color transmission = scene.traceRay(refractedRay, intersection.depth + 1, new_ri, &dist);
        if (dist != 0) {
//            std::cout << absorbance << " " << dist << "\n";
            result += transmission.attenuated(absorbance * dist) * (1 - R);
        }
        else {
            result += transmission * (1 - R);
        }
            }
    else {
//        return Color(1, 0, 0) * (1 - R);
    }

    result += Shiny::computeColor(intersection, scene) * R;
    return result;
}
