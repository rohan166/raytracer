#pragma once

#include "util.h"
#include "Intersection.h"
#include "Material.h"
#include "Prop.h"
#include "Ray.h"

class Sphere : public Prop {
    Point3 center;
    float radius;

public:
    Sphere(float x, float y, float z, float r, const Material &m) : center(x, y, z), radius(r), Prop(m) { }

    Sphere(const Point3 p, float r, const Material &m) : center(p), radius(r), Prop(m) { }

    Intersection *intersects(const Ray &ray) const;
};
