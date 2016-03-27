#pragma once

#include "Intersection.h"
#include "Color.h"

class Scene;

class Intersection;

class Material {
public:
    Color base;
    float kspec = 0;
    float kref = 0;
    float ktrans = 0;
    float ri = 0; // refractive index

    Material(Color base_) : base(base_) { }

    Material(Color base_, float kspec_, float kref_, float ktrans_, float ri_) : base(base_), kspec(kspec_),
                                                                                 kref(kref_), ktrans(ktrans_),
                                                                                 ri(ri_) { }

    Color computeColor(const Intersection& intersection, const Scene& scene) const;
};  
