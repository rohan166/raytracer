#include <iostream>
#include "Scene.h"
#include "Sampler.h"
#include "Sphere.h"
#include "Camera.h"
#include "Sample.h"
#include "Intersection.h"
#include "Pixel.h"

using namespace std;

int main(int argc, char* argv[]) {
    Scene scene;
    Color sphereColor(128, 128, 128);
    Material m(0.5, sphereColor);
    scene.addProp(new Sphere(200, 200, 200, 100, m));
    Camera& camera = scene.getCamera();
    int total_c = 0, not_found_c = 0;
    for (int y = 0; y < 480; y++) {
        for (int x = 0; x < 640; x++) {
            total_c++;
            Sample sample(((double) x) / 640.0, ((double) y) / 480.0);
            Ray ray = camera.getRay(sample);
            cout << "Tracing " << ray << '\n';
            Intersection* intersection = scene.castRay(ray);
            if (!intersection) {
                not_found_c++;
                sample.color = Color(0, 0, 0);
            }
            else {
                sample.color = intersection->prop.material.computeColor(*intersection, scene);
            }
            camera.writePixel(Pixel(x, y, sample.color));
        }
    }
    cerr << "Total count : " << total_c << endl;
    cerr << "Not found count : " << not_found_c << endl;
}
