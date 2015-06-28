#ifndef RAYTRACER_SAMPLE_H
#define RAYTRACER_SAMPLE_H

#include "Color.h"

class Sample {
private:
    Color color;
    int x, y;
public:
    void setColor(const Color &color) {
        this->color = color;
    }


public:
    Sample(const Color &color, int x, int y) : color(color), x(x), y(y) { }
};


#endif //RAYTRACER_SAMPLE_H
