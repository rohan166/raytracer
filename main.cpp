#include <iostream>
#include "Scene.h"
#include "Sampler.h"
#include "Camera.h"
#include "Sample.h"
#include "Intersection.h"
#include "Pixel.h"

using namespace std;

int main(int argc, char* argv[]) {
    Scene scene;
    Camera &camera = scene.getCamera();
    Sampler &sampler = scene.getSampler();
    for (Sample &sample: sampler.getSamples()) {
        Ray ray = camera.getRay(sample);
        Intersection* intersection = scene.castRay(ray);
        if (!intersection) sample.setColor(Color(0, 0, 0));
        else sample.setColor(intersection->getColor());
        sampler.resolve(sample);
    }
    for (const Pixel &pixel: sampler.getPixels()) {
        camera.writePixel(pixel);
    }
}
