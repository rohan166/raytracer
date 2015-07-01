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
            Sample sample(((double) x) / 640.0, ((double) y) / 480.0);
            Ray ray = camera.getRay(sample);
            cout << "Tracing " << ray << '\n';
            Intersection* intersection = scene.castRay(ray);
            if (!intersection) sample.color = Color(0, 0, 0);
            else sample.color = intersection->prop.material.computeColor(*intersection);
            camera.writePixel(Pixel(x, y, sample.color));
        }
    }
}
