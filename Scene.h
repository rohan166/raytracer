#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include "Camera.h"

class Scene {
private:
    static Scene *instance;

    Scene();

public:
    Camera camera;
    static Scene &get();
};


#endif //RAYTRACER_SCENE_H
