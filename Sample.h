#ifndef RAYTRACER_SAMPLE_H
#define RAYTRACER_SAMPLE_H

#include "Color.h"

class Sample {
public:
    Color color;
    int x, y;

public:
    Sample(const Color& color, int x, int y) : color(color), x(x), y(y) { }
};


#endif //RAYTRACER_SAMPLE_H
