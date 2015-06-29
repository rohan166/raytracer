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
    Vector3 up;
    Vector3 right;

public:
    Camera(const Ray& ray_, const Vector3& up_, double hfov) : ray(ray_) {
        ray.direction.normalize();
        right = ray.direction.crossProduct(up_);
        up = right.crossProduct(ray.direction);

        double screen_width = tan(hfov * 90);
    }

    Ray getRay(Sample sample) {
        return Ray(Point3(0, 0, 0), Vector3(0, 0, 0));
    }

    void writePixel(Pixel pixel) { }

private:
    Color** pixels;
};


#endif //RAYTRACER_CAMERA_H
