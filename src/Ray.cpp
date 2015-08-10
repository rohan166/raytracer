#include "Ray.h"

std::ostream &operator<<(std::ostream &out, const Ray &ray) {
    out << "Ray(" << ray.p << " + t*" << ray.d << ")";
    return out;
}
