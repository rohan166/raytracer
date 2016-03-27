#include "Triangle.h"

Triangle::Triangle(Point3 n, Point3 e, Point3 f, Material m) : a(e - n), b(f - n), Plane(m, n, (e -
                                                                                                n).crossProduct(
        f - n)) {
    if (a.isParallel(b)) {
        throw "points of a triangle can't be collinear";
    }
}

Intersection* Triangle::intersects(const Ray& ray) const {
    Intersection* i = Plane::intersects(ray);
    if (!i) return nullptr;

    // is the intersection point inside the a and b edges?
    if (a.crossProduct(i->location - p).dot(n) < 0) return nullptr;
    if (b.crossProduct(i->location - p).dot(n) > 0) return nullptr;

    // is the intersection point inside the edge between A and B?
    Vector3 ab = b - a;
    Point3 A = p + a;
    if (ab.crossProduct(i->location - A).dot(n) < 0) return nullptr;

    return i;
}
