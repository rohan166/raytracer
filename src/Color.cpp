#include "Color.h"


std::ostream& operator<<(std::ostream& out, const Color& color) {
    out << "<" << color.components[0] << ", " << color.components[1] << ", " <<
    color.components[2] << ">";
    return out;
}