#ifndef RAYTRACER_UTIL_H
#define RAYTRACER_UTIL_H

#define EPS (0.0)

inline float min(float a, float b) {
    if (a < b)
        return a;
    return b;
}

inline float sqr(float a) {
    return a*a;
}

#endif //RAYTRACER_UTIL_H
