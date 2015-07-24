#include "Intersection.h"
#include "Material.h"
#include "Color.h"
#include "Scene.h"
#include "Ray.h"

#ifndef RAYTRACER_PRIMITIVE_H
#define RAYTRACER_PRIMITIVE_H

class Scene;

class Material;

class Intersection;

class Prop {
public:
    const Material &material;

    Prop(const Material &m) : material(m) { }

    virtual Intersection *intersects(const Ray &ray, const Scene &scene) = 0;
};

#endif //RAYTRACER_PRIMITIVE_H
