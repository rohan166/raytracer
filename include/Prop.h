#pragma once

#include "Material.h"

class Scene;

class Material;

class Intersection;

class Ray;

class Prop {
public:
    const Material& material;

    Prop(const Material& m) : material(m) { }

    // Does the ray intersect the prop? This function assumes a normalized ray
    virtual Intersection intersects(const Ray &ray) const = 0;
};

