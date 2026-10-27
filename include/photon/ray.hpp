#pragma once

#include "photon/vector3.hpp"
namespace photon {
/**
 * @brief Represents a ray with an origin and a direction
 */
class Ray {
public:
  /// Default constructs a ray at the origin with a zero direction
  Ray();

  /**
   * @brief Constructs a ray from an origin and a direction
   *
   * @param origin The starting point of the ray
   * @param direction The direction of the ray
   */
  Ray(const Vector3 &origin, const Vector3 &direction);

  /// Returns the origin of the ray
  const Vector3 &Origin() const;
  /// Returns the direction of the ray
  const Vector3 &Direction() const;

  /**
   * @brief Returns the point along the ray at the given parameter
   *
   * @param t The distance parameter along the ray
   *
   * @return The point origin + t * direction
   */
  Vector3 At(double t) const;

private:
  Vector3 origin, direction;
};
} // namespace photon
