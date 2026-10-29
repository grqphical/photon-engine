#pragma once

#include <limits>
#include <random>

namespace photon {
/// A convenient alias for positive floating point infinity
const double infinity = std::numeric_limits<double>::infinity();

inline double RandomDouble() {
  static std::uniform_real_distribution<double> distribution(0.0, 1.0);
  static std::mt19937 generator;
  return distribution(generator);
}

inline double RandomDouble(double min, double max) {
  return min + (max - min) * RandomDouble();
}

} // namespace photon
