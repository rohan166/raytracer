#ifndef RAYTRACER_POINT2_H
#define RAYTRACER_POINT2_H

class Vector2;

#include "Vector2.h"

class Point2 {
    friend class Vector2;

    float coords[2];

public:
    Point2(float x, float y) : coords{x, y} { }

    Vector2 operator-(const Point2 &other) const;

    Point2  operator+(const Vector2 &other) const;
};


#endif //RAYTRACER_Point2_H
