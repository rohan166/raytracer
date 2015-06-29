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
    Camera& camera = scene.getCamera();
    for (int y = 0; y < 480; y++) {
        for (int x = 0; x < 640; x++) {
            Sample sample(x, y);
            Ray ray = camera.getRay(sample);
            Intersection* intersection = scene.castRay(ray);
            if (!intersection) sample.color = Color(0, 0, 0);
            else sample.color = intersection->getColor();
            camera.writePixel(Pixel(x, y, sample.color));
        }
    }
}
