#ifndef RAYTRACER_PIXEL_H
#define RAYTRACER_PIXEL_H

#include "Color.h"
#include <iostream>

class Pixel {
public:
    int x, y;
    Color color;


    Pixel(int x, int y, const Color &color) : x(x), y(y), color(color) { }
};


#endif //RAYTRACER_PIXEL_H
