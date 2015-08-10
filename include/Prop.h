#include "Intersection.h"
#include "Material.h"
#include "Color.h"
#include "Scene.h"
#include "Ray.h"

#ifndef RAYTRACER_PROP_H
#define RAYTRACER_PROP_H

class Scene;

class Material;

class Intersection;

class Prop {
public:
    const Material &material;

    Prop(const Material &m) : material(m) { }

    virtual Intersection *intersects(const Ray &ray) = 0;
};

#endif //RAYTRACER_PROP_H
