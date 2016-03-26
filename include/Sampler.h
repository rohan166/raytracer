#ifndef RAYTRACER_SAMPLER_H
#define RAYTRACER_SAMPLER_H

#include <vector>
#include "Sample.h"
#include "Pixel.h"


class Sampler {
    int hpixels, vpixels;
public:
    Sampler() { }

    Sampler(int hpixels, int vpixels) : hpixels(hpixels), vpixels(vpixels) { }

    virtual std::vector<Sample> getSamples() const;

    virtual std::vector<Pixel> getPixels() const;

    void resolve(Sample sample) { }

};


#endif //RAYTRACER_SAMPLER_H
