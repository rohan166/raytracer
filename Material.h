#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


#include "Intersection.h"
#include "Color.h"

class Material {
    double reflectivity;
    Color diffuse_color;

    Color compute_color(Intersection intersection) {
        return Color(1.0, 1.0, 1.0);
    }
};

#endif //RAYTRACER_MATERIAL_H
