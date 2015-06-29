#ifndef RAYTRACER_POINT3_H
#define RAYTRACER_POINT3_H

class Vector3;

#include "Vector3.h"

class Point3 {
public:
    float coords[3];

    Point3() { }

    Point3(float x, float y, float z) : coords{x, y, z} { }

    Vector3 operator-(const Point3& other) const;
    Point3  operator+(const Vector3& other) const;
    Point3  operator-(const Vector3& other) const;
};


#endif //RAYTRACER_POINT3_H
