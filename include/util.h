#pragma once

#include <cstdlib>

#define EPS (0.0001)

inline float min(float a, float b) {
    if (a < b)
        return a;
    return b;
}

inline float max(float a, float b) {
    if (a > b)
        return a;
    return b;
}


inline float sqr(float a) {
    return a * a;
}

inline double min(double a, double b) {
    if (a < b)
        return a;
    return b;
}

inline double sqr(double a) {
    return a * a;
}

// Return a random float in [0, 1]
inline float rand_float() {
    return (float) rand() / (float) (RAND_MAX);
}
