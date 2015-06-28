#ifndef RAYTRACER_PIXEL_H
#define RAYTRACER_PIXEL_H

#include "Color.h"

class Pixel {
    int x, y;
    Color color;

public:
    Pixel(int x, int y, const Color &color) : x(x), y(y), color(color) { }
};


#endif //RAYTRACER_PIXEL_H
