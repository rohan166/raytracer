#include <iostream>
#include <Plane.h>
#include "Scene.h"
#include "Sphere.h"

using namespace std;

int main(int argc, char *argv[]) {
    int hpixels = 1000, vpixels = 1000;
    Camera camera(Ray(Point3(2, 5, 5), Point3(0, 3, -2)),
                  Vector3(0, 1, 0),
                  120, hpixels, vpixels);

    // A dark gray background
    Scene scene(Color(0.05, 0.05, 0.05));

    // A gray material
    Material gray(0, Color(1, 1, 1) * 0.7);

    // Build a 5 sided box
    // Planes parallel to XZ
    scene.addProp(new Plane(gray, Point3(0, 0, 0), Vector3(0, 1, 0)));
    scene.addProp(new Plane(gray, Point3(0, 6, 0), Vector3(0, 1, 0)));

    // Planes parallel to YZ
    scene.addProp(new Plane(Material(0, Color(1, 0, 0)),
                            Point3(-3, 0, 0), Vector3(1, 0, 0)));
    scene.addProp(new Plane(Material(0, Color(0, 1, 0)),
                            Point3(3, 0, 0), Vector3(1, 0, 0)));

    // Plane parallel to XY
    scene.addProp(new Plane(Material(0.4, Color(0,0,0)), Point3(0, 0, -6), Vector3(0, 0, 1)));

    // Put a blue and yellow sphere in the box
    scene.addProp(new Sphere(Point3(1, 1, -2), 1, Material(0.4, Color(0, 0, 1))));
    scene.addProp(new Sphere(Point3(-1, 4, -4), 1.5, Material(0.4, Color(1, 1, 0))));

    // White light in the middle of the room
    scene.addLight(new Light(Point3(0, 5, 2), Color(1, 1, 1) * 0.5));
    // Blue light right of center
    scene.addLight(new Light(Point3(2, 5, -3), Color(0.5, 0.5, 1) * 0.5));

    for (int y = 0; y < vpixels; y++) {
        for (int x = 0; x < hpixels; x++) {
            Color sum;
            // Take 10 samples inside the pixel
            int num_samples = 1;
            for (int i = 0; i < num_samples; i++) {
                Sample sample((x + rand_float()) / hpixels, (y + rand_float()) / vpixels);
                Ray ray = camera.getRay(sample);
                sum += scene.traceRay(ray);
            }
            camera.writePixel(Pixel(x, y, sum * (1.0 / num_samples)));
        }
    }
}
