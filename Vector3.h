#ifndef PROJECT_VECTOR3_H
#define PROJECT_VECTOR3_H

#include "Triplet.h"

class Vector3 : public Triplet {
    float magnitude;
public:
    Vector3(float x, float y, float z, float m);
    Vector3(Triplet &t, float m);
    Vector3(Point &first, Point &second);

    void scale(float coefficient);
    Vector3 scaled(float coefficient);

    void normalize();
    Vector3 normalized();
};


#endif //PROJECT_VECTOR3_H
