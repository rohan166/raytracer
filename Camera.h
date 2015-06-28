#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "Ray.h"
#include "Scene.h"
#include "Color.h"

class Camera {
    Ray ray;

public:
    Camera(const Ray &ray) : ray(ray) { }

private:
    Color** pixels;
};


#endif //RAYTRACER_CAMERA_H
