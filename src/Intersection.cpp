#include "Intersection.h"

Intersection::Intersection(double t, Ray r, Vector3 n, const Prop &p) : incidentRay(r), t(t), normal(n), prop(p) {
    this->location = incidentRay.p + incidentRay.d * t;
    this->normal.normalize();
    Vector3 reflected = incidentRay.d - normal.scaled(2 * (incidentRay.d.dot(normal)));
    this->reflectedRay = Ray(location, reflected);
}
