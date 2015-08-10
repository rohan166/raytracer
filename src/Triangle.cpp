#include "Triangle.h"
#include "Plane.h"
#include "Intersection.h"

Triangle::Triangle(Point3 &n, Point3 &e, Point3 &f, Material &m) :
        a(n-e), b(n-f), Plane(m, n, (n-e).crossProduct(n-f)) {
    if (a.isParallel(b)) {
        throw "points of a triangle can't be collinear";
    }
}

Intersection* Triangle::intersects(const Ray &ray) const {
    Intersection *i = Plane::intersects(ray);
    return i;
}
