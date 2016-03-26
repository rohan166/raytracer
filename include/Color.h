#pragma once

#include <iostream>

class Color {
public:
    float components[3];

    Color() : components{0, 0, 0} { };

    Color(float r, float g, float b) : components{r, g, b} { };

    Color operator+(const Color &other) const;

    Color operator+=(const Color &other);

    Color operator*(float factor) const;

    Color operator*(const Color &other) const {
        return Color(components[0] * other.components[0],
                     components[1] * other.components[1],
                     components[2] * other.components[2]);
    }
};

std::ostream &operator<<(std::ostream &out, const Color &color);
