#ifndef PROJECT_VECTOR3_H
#define PROJECT_VECTOR3_H

class Point3;

#include "Point3.h"

class Vector3 {
public:
    float coords[3];

    Vector3(float x, float y, float z) :
        coords{x, y, z} {};

    Vector3(const Point3& p1, const Point3& p2);

    Vector3 scaled(float coefficient) const;
    Vector3 normalized() const;
};


#endif //PROJECT_VECTOR3_H
