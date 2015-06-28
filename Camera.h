#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H

#include "Ray.h"
#include "Color.h"
#include "Point3.h"
#include "Pixel.h"
#include "Vector3.h"
#include "Sample.h"

class Camera {
    Ray ray;

public:
    Camera(const Ray &ray) : ray(ray) { }

    Ray getRay(Sample sample) {
        return Ray(Point3(0, 0, 0), Vector3(0, 0, 0));
    }

    void writePixel(Pixel pixel) { }

private:
    Color** pixels;
};


#endif //RAYTRACER_CAMERA_H
