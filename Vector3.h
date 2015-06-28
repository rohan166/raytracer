#ifndef PROJECT_VECTOR3_H
#define PROJECT_VECTOR3_H

#include "Triplet.h"

class Vector3 : public Triplet {
    double magnitude;
public:
    Vector3(float x, float y, float z, double m);
    Vector3(Triplet t, double m);

    void scale(double coefficient);
    Vector3 scaled(double coefficient);
};


#endif //PROJECT_VECTOR3_H
