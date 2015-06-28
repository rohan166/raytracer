#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "Camera.h"
#include "Sampler.h"
#include "Vector3.h"


class Scene {
private:
    Camera camera;
    Sampler sampler;

public:
    Scene() : camera(Camera(Vector3(0, 0, 0))) {}
};


#endif //RAYTRACER_SCENE_H
