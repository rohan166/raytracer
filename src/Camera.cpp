#include "Camera.h"

#define PI 3.14159265

Camera::Camera(const Ray &ray_, const Vector3 &up,
               double hfov, int hpixels, int vpixels) : ray(ray_) {
    double screen_width = tan(hfov * PI / 90);
    double screen_height = screen_width * vpixels / hpixels;

    // put the screen 1 unit in front of the camera
    Vector3 forward = ray.d.normalized();

    // construct a new vector that's perpendicular to the camera's direction and the up vector
    right = forward.crossProduct(up.normalized());

    // construct a new vector that's perpendicular to the camera's direction and the right vector
    down = forward.crossProduct(right);

    // now we have an orthonormal basis for screen space!

    // scale the vectors so they are the same size as the screen
    right *= screen_width;
    down *= screen_height;

    // save the top left corner of the screen
    screen_origin = ray.p + forward - right / 2 - down / 2;

    fs.open("image.ppm", std::fstream::out);
    fs << "P6\n640 480\n255\n";
}

Ray Camera::getRay(Sample sample) {
    Point3 screen_point = screen_origin + down * sample.y + right * sample.x;
    return Ray(ray.p, Vector3(ray.p, screen_point));
}

void Camera::writePixel(Pixel pixel) {
    unsigned char buf[3] = {(unsigned char) pixel.color.components[0],
                            (unsigned char) pixel.color.components[1],
                            (unsigned char) pixel.color.components[2]};
    fs.write((char *) buf, 3);
}
