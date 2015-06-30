#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "Ray.h"
#include "Color.h"
#include "Point3.h"
#include "Pixel.h"
#include "Vector3.h"
#include "Sample.h"
#include <iostream>

class Camera {
    Ray ray;
    Vector3 down;
    Vector3 right;
    Point3 screen_origin;

public:
    Camera(const Ray &ray_, const Vector3 &up, double hfov, int hpixels, int vpixels) : ray(ray_) {
        double screen_width = tan(hfov / 2 * 90);
        double screen_height = screen_width * vpixels / hpixels;

        // put the screen 1 unit in front of the camera
        ray.d.normalize();
        
        // construct a new vector that's perpendicular to the camera's direction and the up vector
        right = ray.d.crossProduct(up).normalized();

        // construct a new vector that's perpendicular to the camera's direction and the right vector
        down = ray.d.crossProduct(right);

        // now we have an orthonormal basis for screen space!

        // scale the vectors so they are the same size as the screen
        right *= screen_width;
        down *= screen_height;

        // save the top left corner of the screen
        screen_origin = ray.p + ray.d - right / 2 - down / 2;
    }

    Ray getRay(Sample sample) {
        Point3 screen_point = screen_origin + down * sample.y + right * sample.x;
        return Ray(ray.p, Vector3(ray.p, screen_point));
    }

    void writePixel(Pixel pixel) { }

private:
    Color **pixels;
};


#endif //RAYTRACER_CAMERA_H
