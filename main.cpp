#include <iostream>
#include "Scene.h"
#include "Sampler.h"
#include "Camera.h"
#include "Sample.h"

using namespace std;

int main(int argc, char* argv[]) {
    Scene &scene = Scene::getInstance();
    Camera &camera = scene.getCamera();
    Sampler &sampler = camera.getCampler();
    for (const Sample &sample: sampler.getSamples()) {
        Ray ray = camera.getRay(sample);
        Intersection* intersection = Scene.cast_ray(ray);
        if (!intersection) sample.setColor(Color(0, 0, 0));
        else sample.setColor(intersection->getColor());
        sampler.resolve(sample);
    }
    for (const Pixel &pixel: sampler.getPixels()) {
        camera.writePixel(pixel);
    }
}
