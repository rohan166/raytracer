#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "Prop.h"
#include "Vector3.h"
#include "Plane.h"

class Triangle : public Plane {
public:
    Vector3 e;
    Vector3 f;

    Triangle(const Material &material, const Point3 &p, const Vector3 &n, const Vector3 &e, const Vector3 &f) :
            Plane(material, p, n) {
        this->e = e;
        this->f = f;
    };

    Intersection *intersects(const Ray &ray, const Scene &scene) const {
        return Plane::intersects(ray, scene);
    }
};


#endif //RAYTRACER_TRIANGLE_H
