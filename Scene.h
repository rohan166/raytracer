#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H

#include <vector>

#include "Camera.h"
#include "Sampler.h"
#include "Vector3.h"
#include "Ray.h"
#include "Intersection.h"
#include "Prop.h"

using namespace std;

class Intersection;

class Scene {
private:

    Camera camera;

    struct Light {
        Point3 origin;
        Color color;
    };

    vector<Light> lightList;
    vector<Prop*> propList;
    Color backgroundColor;

public:

    Scene() : camera(Ray(Point3(0, 0, 0), Vector3(0, 0, -1)), Vector3(0, 1, 0), 90, 640, 480) {
        // eventually we'll initialize both the camera and the sampler from the same
        // point, but for now we're just duplicating this
    }

    Scene(vector<Light> lightList_, vector<Prop*> propList_, Color backgroundColor_) : camera(
            Ray(Point3(0, 0, 0), Vector3(0, 0, -1)), Vector3(0, 1, 0), 90, 640, 480),
                                                                                      lightList(lightList_),
                                                                                      propList(propList_),
                                                                                      backgroundColor(
                                                                                              backgroundColor_) {

    }

    vector<Light>::const_iterator getAllLightSources() const {
        return lightList.begin();
    }

    Camera &getCamera() {
        return camera;
    }

    Intersection *castRay(Ray ray) { return nullptr; }
};


#endif //RAYTRACER_SCENE_H
