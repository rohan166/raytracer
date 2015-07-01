#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H


class Color {
    float components[3];
public:
    Color() { }

    Color(float r, float g, float b) : components{r, g, b} { };
};


#endif //RAYTRACER_COLOR_H
