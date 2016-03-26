#pragma once

#include "Ray.h"

class Scene;

class Material;

class Intersection;

class Prop {
public:
    const Material &material;

    Prop(const Material &m) : material(m) { }

    // Does the ray intersect the prop? This function assumes a normalized ray
    virtual Intersection *intersects(const Ray &ray) const = 0;
};

