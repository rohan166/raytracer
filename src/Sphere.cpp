//
// Created by rray on 8/9/15.
//

#include "Sphere.h"

Intersection* Sphere::intersects(const Ray& ray) {
    /*
     * let's say sphere center is c0, c1, c2 with radius r
     * let's also say that ray origin is o0, o1, o2, and direction is d0, d1, d2
     * then general point on the ray is (t*d0 + o0, t*d1 + o1, t*d2 + o2)
     * if it touches the sphere then,  (p0-c0)^2 + (p1-c1)^2 + (p2-c2)^2 <= r^2 which implies that
     * (t*d0 + o0 - c0)^2 + (t*d1 + o1 - c1)^2 + (t*d2 + o2 - c2)^2 <= r^2 which implies
     * (t^2)*(d0^2 + d1^2 + d2^2) + 2t*(d0*(o0-c0) + d1(o1-c1) + d2(o2-c2)) + (o0-c0)^2 + (o1-c1)^2 + (o2-c2)^2 <= r^2
     * let the coefficient of t^2 be x, coefficient of t be y, and the constant term be z.
     * then t = (-y + sqrt(y^2 - 4xz))/(2x), (-y - sqrt(y^2 - 4xz))/(2x)
     *
     * Now here, float a is d0^2 + d1^2 + d2^2 (aka y), b is sum(d_i*(o_i - c_i)) aka x, and float c is z-r^2
     *
     * If the two values of t thus found have a negative product, no intersection exists
     * If they have a positive product but both are negative, an intersection exists but the ray would have to be
     * extended backwards to reach it so it doesn't really exist in meatspace
     * If they're both non-negative, et voila
     */

    float a = 0, b = 0, c = 0;
    for (int i = 0; i < 3; i++) {
        a += SQR(ray.d.coords[i]);
    }

    for (int i = 0; i < 3; i++) {
        b += ray.d.coords[i] * (ray.p.coords[i] - center.coords[i]);
    }
    b *= 2;

    for (int i = 0; i < 3; i++) {
        c += SQR(center.coords[i]);
        c += SQR(ray.p.coords[i]);
        c -= 2 * center.coords[i] * ray.p.coords[i];
    }
    c -= SQR(radius);

    const double bb4ac = SQR(b) - (4.0 * a * c);

    cerr << "bb4ac for this ray: " << bb4ac << endl;
    cerr << "b: " << b << "\tc: " << c << "\ta: " << a << endl;

    // can't compare floats with 0 directly so we use an error bound EPS
    if (bb4ac > EPS) {
        const float pm = sqrt(bb4ac);
        const float a2 = 2 * a;
        const float t = MIN((-b + pm) / a2, (-b - pm) / a2);
        if (t >= 0) {
            Point3 p(ray.p.coords[0] + ray.d.coords[0] * t, ray.p.coords[1] + ray.d.coords[1] * t,
                     ray.p.coords[2] + ray.d.coords[2] * t);
            Vector3 n(p.coords[0] - center.coords[0], p.coords[1] - center.coords[1],
                      p.coords[2] - center.coords[2]);
            // Change this once we have the Material definition
            return new Intersection(t, ray, n, *this);
        }
    }
    return 0;
}
