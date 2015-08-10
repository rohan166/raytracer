#include "Point2.h"

Vector2 Point2::operator-(const Point2 &other) const {
    Vector2 v(other.coords[0] - coords[0], other.coords[1] - coords[1]);
    return v;
}

Point2  Point2::operator+(const Vector2 &other) const {
    Point2 p(coords[0] + other.coords[0], coords[1] + other.coords[1]);
    return p;
}
