#include "Scene.h"
#include "Camera.h"

Scene &Scene::getInstance() {
    if (!instance) instance = new Scene();
    return *instance;
}

Scene::Scene() {
    camera = Camera(Ray(Point3(0, 0, 0), Vector3(0, 0, -1)));
}