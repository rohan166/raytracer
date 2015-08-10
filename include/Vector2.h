#ifndef PROJECT_VECTOR2_H
#define PROJECT_VECTOR2_H

class Point2;

#include "Point2.h"

class Vector2 {
    friend class Point2;

    float coords[2];

public:
    Vector2(float x, float y) : coords{x, y} { };

    Vector2(const Point2 &p1, const Point2 &p2);

    Vector2 scaled(float coefficient) const;

    void scale(float coefficient);

    double norm() const;

    double norm_squared() const;

    Vector2 normalized() const;
};


#endif //PROJECT_VECTOR3_H
