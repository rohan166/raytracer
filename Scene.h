#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H


#include "Camera.h"
#include "Sampler.h"
#include "Vector3.h"


class Scene {
private:
    static Scene* instance;
    Camera camera;

    Scene() : camera(Camera(Vector3(0, 0, 0))) { }

    Sampler sampler;

public:

    static Scene &getInstance();

    Camera &getCamera() {
        return camera;
    }

    Sampler &getSampler() {
        return sampler;
    }

};


#endif //RAYTRACER_SCENE_H
