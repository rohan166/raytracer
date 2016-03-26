#pragma once

#include "Intersection.h"
#include "Color.h"
#include "Scene.h"

class Scene;

class Intersection;

class Material {
public:
    float reflectivity;
    Color diffuse_color;

    Material(float r, Color dc) : reflectivity(r), diffuse_color(dc) { }

    Color computeColor(const Intersection &intersection, const Scene &scene) const;
};
