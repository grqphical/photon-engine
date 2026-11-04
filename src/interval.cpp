#include "photon/interval.hpp"

namespace photon {

Interval::Interval() : min(+infinity), max(-infinity) {}

Interval::Interval(double min, double max) : min(min), max(max) {}

double Interval::Min() const { return min; }

double Interval::Max() const { return max; }

bool Interval::Contains(double x) const { return min <= x && x <= max; }

bool Interval::Surrounds(double x) const { return min < x && x < max; }

double Interval::Clamp(double x) const {
  if (x < min)
    return min;
  if (x > max)
    return max;
  return x;
}

double Interval::Size() const { return max - min; }

} // namespace photon
