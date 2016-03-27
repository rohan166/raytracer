#pragma once

#include "Intersection.h"
#include "Point3.h"
#include "Prop.h"
#include "Ray.h"

class Intersection;

class Plane : public Prop {
public:
    Point3 p;  // any point on the plane
    Vector3 n; // the normal vector of the plane

    // Vector3 n should be an object but it wasn't clear how to
    // construct a normal in the member initialization list in Triangle's constructor
    Plane(const Material &material, Point3 p, Vector3 n) : Prop(material), p(p), n(n.normalized()) { }

    virtual Intersection intersects(const Ray &ray) const;
};
