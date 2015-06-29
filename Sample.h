#ifndef RAYTRACER_SAMPLE_H
#define RAYTRACER_SAMPLE_H

#include "Color.h"

class Sample {
public:
    Color color;
    int x, y;

    Sample(int x, int y) : x(x), y(y) { }
};


#endif //RAYTRACER_SAMPLE_H
