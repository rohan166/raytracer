#include "Point3.h"
#include "Vector3.h"

Point3::Point3(float x, float y, float z): Triplet(x, y, z) {}

Vector3 Point3::operator-(Point3 &other) {
    return new Vector3(this, other);
}

Point3 Point3::operator+(Vector3 &other) {
    v[0] += other.magnitude*other.first();
    v[1] += other.magnitude*other.second();
    v[2] += other.magnitude*other.third();
}
