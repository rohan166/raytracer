#ifndef RAYTRACER_SAMPLE_H
#define RAYTRACER_SAMPLE_H

#include "Color.h"

class Sample {
public:
    Color color;
    double x, y;

    Sample(double x, double y) : x(x), y(y) { }
};


#endif //RAYTRACER_SAMPLE_H
