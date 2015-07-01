#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


#include "Intersection.h"
#include "Color.h"

class Material {
public:
    double reflectivity;
    Color diffuse_color;

    Color computeColor(const Intersection &intersection) const {
        return Color(1.0, 1.0, 1.0);
    }
};

#endif //RAYTRACER_MATERIAL_H
