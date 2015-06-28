#ifndef RAYTRACER_POINT3_H
#define RAYTRACER_POINT3_H


#include "Triplet.h"

class Point3 : public Triplet {
public:
    Point3 (float x, float y, float z);
    Vector3* operator-(Point3 &other);
    void operator+=(Vector3 &other);
    Point3* operator+(Vector3 &other);
};


#endif //RAYTRACER_POINT3_H
