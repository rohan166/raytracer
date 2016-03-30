#include "Camera.h"
#include "util.h"

#define PI 3.14159265

Camera::Camera(const Ray& ray_, const Vector3& up, double hfov, int hpixels, int vpixels,
               float gamma_) : ray(ray_), gamma(gamma_), hpixels(hpixels), vpixels(vpixels) {
    film = new Color[hpixels * vpixels];
    double screen_width = 2 * tan(hfov * PI / 360);
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
}

Ray Camera::getRay(Sample sample) {
    Point3 screen_point = screen_origin + down * sample.y + right * sample.x;
    return Ray(ray.p, Vector3(ray.p, screen_point));
}

void Camera::writePixel(Pixel pixel) {
    film[pixel.y * hpixels + pixel.x] = pixel.color;
}

void Camera::writeImage(char* filename) {
    float max_mag = 0;
    for (int i = 0; i < vpixels * hpixels; i++) {
        max_mag = max(film[i].components[0], max_mag);
        max_mag = max(film[i].components[1], max_mag);
        max_mag = max(film[i].components[2], max_mag);
    }

    //if (max_mag < 1) max_mag = 1;

    std::ofstream fs;
    fs.open(filename, std::fstream::out);
    fs << "P6\n" << hpixels << " " << vpixels << "\n255\n";

    for (int i = 0; i < vpixels * hpixels; i++) {
        for (int j = 0; j < 3; j++) {
            const unsigned char c = pow(film[i].components[j] / max_mag, gamma) * 255;
            fs.put(c);
        }
    }
    fs.close();
}
