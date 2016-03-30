#include <Sample.h>

std::ostream& operator<<(std::ostream& out, const Sample& sample) {
  out << "(" << sample.x << ", " << sample.y << "): " << sample.color;
  return out;
}
