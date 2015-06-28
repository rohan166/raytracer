#ifndef RAYTRACER_SAMPLER_H
#define RAYTRACER_SAMPLER_H

#include <vector>
#include "Sample.h"
#include "Pixel.h"


class Sampler {
public:
    std::vector <Sample> getSamples() { return std::vector<Sample>(); }
    std::vector <Pixel> getPixels() { return std::vector<Pixel>(); }
    void resolve(Sample sample) { }

};


#endif //RAYTRACER_SAMPLER_H
