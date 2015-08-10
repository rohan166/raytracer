#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


#include "Intersection.h"
#include "Color.h"
#include "Scene.h"

class Scene;

class Intersection;

class Material {
public:
    double reflectivity;
    Color diffuse_color;

    Color computeColor(const Intersection& intersection, const Scene& scene) const;
};

#endif //RAYTRACER_MATERIAL_H
