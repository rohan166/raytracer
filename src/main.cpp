#include <iostream>
#include <Plane.h>
#include "Scene.h"
#include "Sphere.h"

using namespace std;

int main(int argc, char *argv[]) {
    Camera camera(Ray(Point3(2, 5, 5), Point3(0, 3, -2)),
                  Vector3(0, 1, 0),
                  120, 640, 480);

    // A dark gray background
    Scene scene(Color(0.05, 0.05, 0.05));

    // A gray material
    Material gray(0.3, Color(1, 1, 1) * 0.7);

    // Build a 5 sided box
    // Planes parallel to XZ
    scene.addProp(new Plane(gray, Point3(0, 0, 0), Vector3(0, 1, 0)));
    scene.addProp(new Plane(gray, Point3(0, 6, 0), Vector3(0, 1, 0)));

    // Planes parallel to YZ
    scene.addProp(new Plane(Material(0.3, Color(1, 0, 0)),
                            Point3(-3, 0, 0), Vector3(1, 0, 0)));
    scene.addProp(new Plane(Material(0.3, Color(0, 1, 0)),
                            Point3(3, 0, 0), Vector3(1, 0, 0)));

    // Plane parallel to XY
    scene.addProp(new Plane(gray, Point3(0, 0, -6), Vector3(0, 0, 1)));

    // Put a blue and yellow sphere in the box
    scene.addProp(new Sphere(Point3(1, 1, -2), 1, Material(0.3, Color(0, 0, 1))));
    scene.addProp(new Sphere(Point3(-1, 4, -4), 1.5, Material(0.3, Color(1, 1, 0))));

    // White light in the middle of the room
    scene.addLight(new Light(Point3(0, 5, 2), Color(1, 1, 1) * 0.5));
    // Blue light right of center
    scene.addLight(new Light(Point3(2, 5, -3), Color(0.5, 0.5, 1) * 0.5));

    // TODO: un-hardcode image dimensions
    for (int y = 0; y < 480; y++) {
        for (int x = 0; x < 640; x++) {
            Color sum;
            // Take 10 samples inside the pixel
            for (int i = 0; i < 10; i++) {
                Sample sample((x + rand_float()) / 640.0, (y + rand_float()) / 480.0);
                Ray ray = camera.getRay(sample);
                Intersection *intersection = scene.castRay(ray);
                // TODO: hack to clip scene at z=0; need to implement rectangles
                if (!intersection || intersection->location.coords[2] > 0) {
                    sample.color = scene.backgroundColor;
                } else {
                    sample.color = intersection->prop.material.computeColor(*intersection, scene);
                }
                sum += sample.color;
            }
            camera.writePixel(Pixel(x, y, sum * (1.0 / 10)));
        }
    }
}
