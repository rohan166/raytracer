#include <iostream>
#include "Scene.h"

using namespace std;

int main(int argc, char *argv[]) {
//    Config *draw;
//    Scene *scene = parse_config(draw);
//    draw_world(scene, argc, argv);
    Scene &scene = Scene::get();
    Camera &camera = scene.get_camera();
    Sampler &sampler = camera.get_sampler();
    for (const Sample &sample: sampler.get_samples()) {
        Ray ray = camera.get_ray(sample);
        Intersection *intersection = Scene.cast_ray(ray);
        if (!intersection) {
            sample.resolve(Color(0, 0, 0));
            continue;
        }
        sample.resolve(intersection->get_color());
    }
    for (const Pixel &pixel: sampler.get_pixels()) {
        camera.write_pixel(pixel);
    }
    return 0;
}