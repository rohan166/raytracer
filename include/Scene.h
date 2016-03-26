#pragma once

#include <vector>

#include "Camera.h"
#include "Sampler.h"
#include "Vector3.h"
#include "Ray.h"
#include "Intersection.h"
#include "Prop.h"

using namespace std;

class Light {
public:
    Point3 origin;
    Color color;

    Light(Point3 origin_, Color color_) : origin(origin_), color(color_) { }
};

class Intersection;

class Scene {
private:
    vector<Light *> lightList;
    vector<Prop *> propList;
public:
    Color backgroundColor;

    Scene(Color backgroundColor_) : backgroundColor(backgroundColor_) { }

    vector<Light *> getAllLightSources() const {
        return lightList;
    }

    Intersection *castRay(Ray ray) const { return castRay(ray, INFINITY); }

    // Ignore intersections past max_t
    Intersection *castRay(Ray ray, float max_t) const;


    Scene &addProp(Prop *prop) {
        propList.push_back(prop);
        return *this;
    }

    Scene &addLight(Light *light) {
        lightList.push_back(light);
        return *this;
    }
};