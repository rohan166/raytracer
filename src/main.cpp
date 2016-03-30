#include <iostream>
#include <Plane.h>
#include <RenderOutput.h>
#include <Sphere.h>
#include <Triangle.h>
#include "Scene.h"

using namespace std;

int main(int argc, char* argv[]) {
    int hpixels = 1000, vpixels = 1000;
#pragma omp parallel for schedule(dynamic)
    for (int t = 0; t < 100; t++) {
        float s = pow(sin(3.141592 / 2.0 * (t / 100.0)), 2);
        cout << s << endl;

        Camera camera(Ray(Point3(-2 + 3 * s, 4.5 - 3 * s + 0.5 * s * s, 5 - s), Point3(0, 3, -2)),
                      Vector3(s / 5.0, 1, 0), 60, hpixels, vpixels, 0.45);

        // A dark gray background
        Scene scene(Color(0.01, 0.01, 0.01));

        // A gray material
        Diffuse gray(Color(1, 1, 1) * 0.7);

        // Build a 5 sided box
        // Planes parallel to XZ

        scene.addProp(new Plane(gray, Point3(0, 0, 0), Vector3(0, 1, -0.2)));
        scene.addProp(new Plane(gray, Point3(0, 6, 0), Vector3(0, 1, 0)));

        // Planes parallel to YZ
        Diffuse green(Color(0, 1, 0)), red(Color(1, 0, 0));
        scene.addProp(new Plane(green, Point3(-3, 0, 0), Vector3(1, 0, 0)));
        scene.addProp(new Plane(red, Point3(3, 0, 0), Vector3(1, 0, 0)));

        Metal silver(Color(1, 1, 1) * 0.5);
        // Plane parallel to XY
        scene.addProp(new Plane(gray, Point3(0, 0, -10), Vector3(0, 0, 1)));

        Shiny yellow(Color(1, 1, 0), 0.2, 0, 100);
        Shiny blue(Color(0, 0, 1), 0.2, 0, 100);
        Shiny white(Color(1, 1, 1), 0.2, 0, 100);

        Metal gold(Color(0xE5, 0xBF, 0x65) * (1.0 / 255));
        Glass glass(0.4, 1.5);
        Glass redglass(0.4, 1.5, Color(1, 0.5, 0.5), 0.15);
        Glass water(0.4, 1.33, Color(0.5, 0.5, 1), 0.05);
        scene.addProp(new Sphere(Point3(1.5, 1.5, -2), 1, white));
        scene.addProp(new Sphere(Point3(-1, 4, -7), 1, blue));
//        scene.addProp(new Sphere(Point3(-2, 1, -1), 0.8, gold));
        scene.addProp(new Sphere(Point3(0, 2.5, -1), 0.8, redglass));
        scene.addProp(new Sphere(Point3(-2, 3.5, -1), 0.8, glass));
        scene.addProp(new Triangle(Point3(1, 1, -3), Point3(1, 4, -7), Point3(2.7, 4, -7), yellow));

        // White light in the middle of the room
        scene.addLight(new Light(Point3(0, 5, 2), Color(1, 1, 1)));
        scene.addLight(new Light(Point3(0, 5, -7), Color(1, 1, 1)));
        // Blue light right of center
        scene.addLight(new Light(Point3(2, 5, -3), Color(0.5, 0.5, 1) * s));
        PNGOutput out;

        for (int i = 0; i < hpixels * vpixels; i++) {
            int x = i % hpixels;
            int y = i / hpixels;
            Color sum;

            // oversampling level
            int l = 10;
            for (int j = 0; j < l; j++) {
                Sample sample(x + 0.5, y + 0.5);
                // perturb the sample
                sample.x += rand_offset() / 2;
                sample.y += rand_offset() / 2;
                sample.x /= hpixels;
                sample.y /= vpixels;
                Ray ray = camera.getRay(sample);
                sample.color = scene.traceRay(ray);
                out.writeSample(sample);
            }
        }
        char filename[30];
        snprintf(filename, sizeof(filename), "out/image%03d.png", t);
        FILE* ofile = fopen(filename, "w+");
        out.rasterize(hpixels, vpixels);
        out.writeFile(ofile);
        fclose(ofile);
    }
}
