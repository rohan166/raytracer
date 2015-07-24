#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H

#include "Prop.h"
#include "Vector3.h"

class Triangle : public Plane {

    Vector3 e;
    Vector3 f;

    Triangle() { };

    Triangle(const Vector3 &n, const Vector3 &e, const Vector3 &f) {
        this->n = n;
        this->e = e;
        this->f = f;
    };

    Intersection *intersects(const Ray &ray) const {
        Intersection i = Plane::intersects(ray);
        if (i == nullptr) return i;

    }
};


#endif //RAYTRACER_TRIANGLE_H
