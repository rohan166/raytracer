#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H


#include "Camera.h"
#include "Sampler.h"

class Scene {
private:
    static Scene* instance;
    Camera camera;
    Sampler sampler;

    Scene();

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
