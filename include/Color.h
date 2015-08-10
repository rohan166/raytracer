#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H


class Color {
public:
    float components[3];

    Color() : components{0, 0, 0} { };

    Color(float r, float g, float b) : components{r, g, b} { };

    Color operator+(const Color& other) const;

    Color operator+=(const Color& other);

    Color operator*(float factor) const;
};


#endif //RAYTRACER_COLOR_H
