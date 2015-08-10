#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "util.h"
#include "Intersection.h"
#include "Prop.h"
#include "Ray.h"

class Sphere : public Prop {
    Point3 center;
    float radius;

public:
    Sphere(float x, float y, float z, float r, Material& m) : center(x, y, z), radius(r), Prop(m) { }

    Sphere(Point3& p, float r, Material m) : center(p), radius(r), Prop(m) { }

    Intersection* intersects(const Ray& ray) const;
};

#endif //RAYTRACER_SPHERE_H
