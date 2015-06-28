#include "Triplet.h"

Triplet::Triplet(float v0, float v1, float v2) {
    v[0] = v0;
    v[1] = v1;
    v[2] = v2;
}

float Triplet::first() {
    return v[0];
}

float Triplet::second() {
    return v[1];
}

float Triplet::third() {
    return v[2];
}
