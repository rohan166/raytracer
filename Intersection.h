#ifndef RAYTRACER_INTERSECTION_H
#define RAYTRACER_INTERSECTION_H

#include "Color.h"

class Intersection {
    Color color;
public:
    Color getColor() {
        return color;
    }
};


#endif //RAYTRACER_INTERSECTION_H
