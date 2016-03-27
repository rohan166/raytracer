#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "Ray.h"
#include "Color.h"
#include "Point3.h"
#include "Pixel.h"
#include "Vector3.h"
#include "Sample.h"
#include <iostream>
#include <fstream>

class Camera {
    Ray ray;
    Vector3 down;
    Vector3 right;

    Color* film;
    int hpixels, vpixels;
    float gamma;

public:
    Point3 screen_origin;

    // What do all the params mean?
    Camera(const Ray& ray_, const Vector3& up, double hfov, int hpixels, int vpixels, float gamma);
    ~Camera() {
        delete film;
    }
    Ray getRay(Sample sample);

    void writePixel(Pixel pixel);

    void writeImage(char* filename);
};


#endif //RAYTRACER_CAMERA_H
