#include <iostream>
#include <Plane.h>
#include <Triangle.h>
#include "Scene.h"
#include "Sphere.h"

using namespace std;

int main(int argc, char* argv[]) {
    int hpixels = 500, vpixels = 500;

#pragma omp parallel for
    for (int t = 0; t < 400; t++) {
        char buffer[30]; // make sure it's big enough
        snprintf(buffer, sizeof(buffer), "out/image%03d.ppm", t);
        std::ofstream fs;
        fs.open(buffer, std::fstream::out);
        fs << "P6\n" << hpixels << " " << vpixels << "\n255\n";

        float s = pow(sin(3.141592 / 2.0 * (t / 400.0)), 2);
        cout << s << endl;

        Camera camera(Ray(Point3(-2 + 3 * s, 4.5 - 3 * s, 5 - s), Point3(0, 3, -2)),
                      Vector3(0, 1, 0), 120, hpixels, vpixels, 0.45);

        // A dark gray background
        Scene scene(Color(0.05, 0.05, 0.05));

        // A gray material
        Material gray(Color(1, 1, 1) * 0.7);

        // Build a 5 sided box
        // Planes parallel to XZ
        scene.addProp(new Plane(gray, Point3(0, 0, 0), Vector3(0, 1, 0)));
        scene.addProp(new Plane(gray, Point3(0, 6, 0), Vector3(0, 1, 0)));

        // Planes parallel to YZ
        scene.addProp(new Plane(Material(Color(1, 0, 0)), Point3(-3, 0, 0), Vector3(1, 0, 0)));
        scene.addProp(new Plane(Material(Color(0, 1, 0)), Point3(3, 0, 0), Vector3(1, 0, 0)));

        // Plane parallel to XY
        scene.addProp(new Plane(Material(Color(0, 0, 0), 0, 0.8, 0, 0), Point3(0, 0, -6 - 4 * s),
                                Vector3(0, 0, 1)));

        Material yellow_plastic(Color(1, 1, 0), 0.2, 0, 0, 0);
        // Put a blue and yellow sphere in the box
        scene.addProp(new Sphere(Point3(1.5, 1.5, -2), 1, Material(Color(0, 0, 1), 0.2, 0, 0, 0)));
        scene.addProp(new Sphere(Point3(-1, 4, -4), 1.5, yellow_plastic));

        scene.addProp(new Triangle(Point3(-1, 1, -3), Point3(-1, 4, -4), Point3(1, 4, -4),
                                   yellow_plastic));

        scene.addProp(
                new Sphere(Point3(-1, 1, -1), 1, Material(Color(1, 0.5, 0.5), 0.5, 0, 0.5, 1.2)));

        // White light in the middle of the room
        scene.addLight(new Light(Point3(0, 5, 2), Color(1, 1, 1) * 0.5));
        scene.addLight(new Light(Point3(0, 5, -7), Color(1, 1, 1) * 0.5));
        // Blue light right of center
        scene.addLight(new Light(Point3(2, 5, -3), Color(0.5, 0.5, 1) * 0.5 * s));

        for (int y = 0; y < vpixels; y++) {
            for (int x = 0; x < hpixels; x++) {
                Color sum;
                // Take 10 samples inside the pixel
                int num_samples = 1;
                for (int i = 0; i < num_samples; i++) {
                    Sample sample((x + rand_float() - 0.5) / hpixels,
                                  (y + rand_float() - 0.5) / vpixels);
                    Ray ray = camera.getRay(sample);
                    sum += scene.traceRay(ray);
                }
                Pixel pixel(x, y, sum * (1.0 / num_samples));
                unsigned char buf[3] = {(unsigned char) pixel.color.components[0],
                                        (unsigned char) pixel.color.components[1],
                                        (unsigned char) pixel.color.components[2]};
                fs.write((char*) buf, 3);
            }
        }
    }
}
