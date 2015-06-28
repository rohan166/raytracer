#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H


class Color {
    unsigned char components[3];
public:
    Color(unsigned char r, unsigned char g, unsigned char b) : components{r, g, b} { };
};


#endif //RAYTRACER_COLOR_H
