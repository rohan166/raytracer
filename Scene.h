#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H


#include "Camera.h"
#include "Sampler.h"
#include "Vector3.h"
#include "Ray.h"
#include "Intersection.h"


class Scene {
private:
    Camera camera;
    Sampler sampler;

public:

    Scene() : camera(Ray(Point3(0, 0, 0), Vector3(0, 0, -1)), Vector3(0, 1, 0), 90, 640, 480) { }

    Camera& getCamera() {
        return camera;
    }

    Sampler& getSampler() {
        return sampler;
    }

    Intersection* castRay(Ray ray) { return nullptr; }
};


#endif //RAYTRACER_SCENE_H
