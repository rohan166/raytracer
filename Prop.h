//
// Created by rray on 6/30/15.
//

#include "Intersection.h"
#include "Color.h"
#include "Scene.h"
#include "Ray.h"

#ifndef RAYTRACER_PRIMITIVE_H
#define RAYTRACER_PRIMITIVE_H

class Prop {
public:
    virtual Intersection* intersects(Ray &ray const, Scene &scene const) = 0;
    virtual Color getReflectedColor(Intersection&) = 0;
};

#endif //RAYTRACER_PRIMITIVE_H
