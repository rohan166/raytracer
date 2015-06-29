#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "util.h"

class Sphere {
  float coords[3];
  float radius;

public:
    Sphere(float x, float y, float z, float r) :
        coords{x, y, z}, radius(r)
        {}

    int intersects(const Ray& ray, float *mul1, float *mul2) const {
        float a = 0;
        for(int i = 0; i < 3; i++) {
            a += SQR(ray.d.coords[i]);
        }

        float b = 0;
        for(int i = 0; i < 3; i++) {
            b += ray.d.coords[i]*(ray.p.coords[i] - coords[i]);
        }
        b *= 2;

        float c = 0;
        for(int i = 0; i < 3; i++) {
            c += SQR(coords[i]);
            c += SQR(ray.p.coords[i]);
            c -= 2*coords[i]*ray.p.coords[i];
        }
        c -= SQR(radius);

        const float bb4ac = SQR(b) - (4.0*a*c);

        if(bb4ac < 0) {
            return 0;
        }
        if(bb4ac < EPS) {
            if(mul1) {
                *mul1 = -b / (2 * a);
            }

            return 1;
        }
        else {
            if(mul1 || mul2) {
                const float pm = sqrt(bb4ac);
                const float a2 = 2*a;
                if(mul1) {
                    *mul1 = (-b + pm) / a2;
                }
                if(mul2) {
                    *mul2 = (-b - pm) / a2;
                }
            }
            return 2;
        }
    }
};

#endif //RAYTRACER_SPHERE_H
