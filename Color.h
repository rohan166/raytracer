#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H


class Color {
public:
    float components[3];

    Color() { }

    Color(float r, float g, float b) : components{r, g, b} { };
};


#endif //RAYTRACER_COLOR_H
