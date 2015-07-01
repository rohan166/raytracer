#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H


class Color {
public:
    float components[3];

    Color() : components{0, 0, 0} { };

    Color(float r, float g, float b) : components{r, g, b} { };

    Color operator+(const Color& other) const {
        return Color(components[0] + other.components[0], components[1] + other.components[1],
                     components[2] + other.components[2]);
    }

    Color operator+=(const Color& other) {
        components[0] += other.components[0];
        components[1] += other.components[1];
        components[2] += other.components[2];
        return *this;
    }

    Color operator*(float factor) const {
        return Color(components[0] * factor, components[1] * factor, components[2] * factor);
    }
};


#endif //RAYTRACER_COLOR_H
