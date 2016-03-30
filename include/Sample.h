#pragma once

#include <Color.h>
#include <ostream>

class Sample {
public:
    Color color;
    double x, y;

    Sample(double x, double y) : x(x), y(y) { }
};

std::ostream& operator<<(std::ostream& out, const Sample& sample);
