#pragma once

#include "Intersection.h"
#include "Color.h"

class Light;

class Scene;

class Intersection;

// Base material class
class Material {
public:
    Material() { }

    // Compute the total color of the light returned along the intersection's incident ray
    virtual Color computeColor(const Intersection& intersection, const Scene& scene) const;

    // Compute the contribution of a single light to the intersection's returned color
    virtual Color computeColor(const Intersection& intersection, const Light& light) const {
        // The base material absorbs all light
        return Color();
    }
};

// A material with only Lambertian diffuse reflectance
class Diffuse : public Material {
public:
    Color base;

    Diffuse(Color base) : base(base) { }

    // Compute the color of the light returned along the intersection's incident ray
    virtual Color computeColor(const Intersection& intersection, const Scene& scene) const {
        return Material::computeColor(intersection, scene);
    }

    // Compute the contribution of a single light to the intersection's returned color
    virtual Color computeColor(const Intersection& intersection, const Light& light) const;
};

// A material with diffuse, specular, and reflective properties
class Shiny : public Diffuse {
public:

    // Proportion of specular effect, and exponent for Blinn-Phong
    float kspec = 0;
    float phong_exp = 1;

    // Proportion of light reflected at a 90 degree angle
    float kref = 0;

    Shiny(Color base, float kspec, float kref, float phong_exp) : Diffuse(base), kspec(kspec),
                                                                  kref(kref),
                                                                  phong_exp(phong_exp) { }

    virtual Color computeColor(const Intersection& intersection, const Scene& scene) const;
    virtual Color computeColor(const Intersection& intersection, const Light& light) const;
};

// A material with a tinted reflection
class Metal : public Material {
public:

    Color base;
    Metal(Color base) : base(base) { }

    virtual Color computeColor(const Intersection& intersection, const Scene& scene) const;

    // The surface is unaffected by direct lighting
    virtual Color computeColor(const Intersection& intersection, const Light& light) const {
        return Color();
    }
};

// A material with transparency and reflection
class Glass : public Shiny {
public:

    float ri; // refractive index
    Color absorbance;
    Glass(float kref, float ri, Color translucency, float absorbance_f) : Shiny(Color(0, 0, 0), 0,
                                                                                kref, 0), ri(ri),
                                                                          absorbance(
                                                                                  (Color(1, 1, 1) -
                                                                                   translucency) *
                                                                                  absorbance_f) { }
    Glass(float kref, float ri) : Shiny(Color(0, 0, 0), 0, kref, 0), ri(ri),
                                  absorbance(Color(0, 0, 0)) { }

    virtual Color computeColor(const Intersection& intersection, const Scene& scene) const;
};