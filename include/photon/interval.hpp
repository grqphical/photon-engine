#pragma once

#include "photon/photon.hpp"
namespace photon {

/// @brief Represents a numeric interval
class Interval {
public:
  /// @brief Default constructor, returns an empty interval
  Interval();

  /// @brief Primary constructor
  /// @param min Minimum value for the interval
  /// @param max Maximum value for the interval
  Interval(double min, double max);

  /// @brief Returns the minimum of this interval
  double Min() const;

  /// @brief Returns the maximum of this interval
  double Max() const;

  /// @brief Returns the number of integers between min and max
  double Size() const;

  /// @brief Checks if x is in the interval. Includes both endpoints (i.e. [min,
  /// max])
  bool Contains(double x) const;

  /// @brief Checks if x is in the interval. Does not iclude both endpoints
  /// (i.e. (min, max))
  bool Surrounds(double x) const;

  static const Interval empty, universe;

private:
  double min, max;
};

inline const Interval Interval::empty = Interval(+infinity, -infinity);
inline const Interval Interval::universe = Interval(-infinity, +infinity);

} // namespace photon
