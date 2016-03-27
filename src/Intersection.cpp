#include "Intersection.h"

Intersection::Intersection(double t, Ray r, Vector3 n, const Prop* p) : incidentRay(r), t(t),
                                                                        normal(n), prop(p) {
    this->location = incidentRay.p + incidentRay.d * t;
}
