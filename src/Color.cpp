#include "Color.h"

Color Color::operator+(const Color& other) const {
    return Color(components[0] + other.components[0], components[1] + other.components[1],
                 components[2] + other.components[2]);
}


Color Color::operator+=(const Color& other) {
    components[0] += other.components[0];
    components[1] += other.components[1];
    components[2] += other.components[2];
    return *this;
}

Color Color::operator*(float factor) const {
    return Color(components[0] * factor, components[1] * factor, components[2] * factor);
}
