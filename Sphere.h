#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "util.h"
#include "Intersection.h"
#include "Prop.h"
#include "Ray.h"

class Sphere : public Prop{
    Point3 center;
    float radius;

public:
    Sphere(float x, float y, float z, float r, Material &m) :
            center(x, y, z), radius(r), Prop(m) {}

    Sphere(Point3 &p, float r, Material m):
            center(p), radius(r), material(m) {}

    int intersects(const Ray &ray) const {
        float a = 0;
        for (int i = 0; i < 3; i++) {
            a += SQR(ray.d.coords[i]);
        }

        float b = 0;
        for (int i = 0; i < 3; i++) {
            b += ray.d.coords[i] * (ray.p.coords[i] - center.coords[i]);
        }
        b *= 2;

        float c = 0;
        for (int i = 0; i < 3; i++) {
            c += SQR(center.coords[i]);
            c += SQR(ray.p.coords[i]);
            c -= 2 * center.coords[i] * ray.p.coords[i];
        }
        c -= SQR(radius);

        const float bb4ac = SQR(b) - (4.0 * a * c);

        if (bb4ac > EPS) {
            const float pm = sqrt(bb4ac);
            const float a2 = 2 * a;
            const float t = MIN((-b + pm) / a2, (-b - pm) / a2);
            if (t >= 0) {
                Point3 p(ray.p.coords[0] + ray.d.coords[0] * t,
                         ray.p.coords[1] + ray.d.coords[1] * t,
                         ray.p.coords[2] + ray.d.coords[2] * t);
                Vector3 n(p.coords[0] - center.coords[0],
                          p.coords[1] - center.coords[1],
                          p.coords[2] - center.coords[2]);
                // Change this once we have the Material definition
                return new Intersection(t, ray, n, material.diffuse_color);
            }
        }
        return 0;
    }
};

#endif //RAYTRACER_SPHERE_H
