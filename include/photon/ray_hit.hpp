#pragma once

#include "photon/ray.hpp"
#include "vector3.hpp"
namespace photon {

/**
 * @brief Describes the intersection of a ray with an object
 */
class RayHit {
public:
  /// The point in world space where the ray hit the object
  Vector3 point;
  /// The surface normal at the hit point, oriented against the ray
  Vector3 normal;
  /// The colour of the object at the hit point
  Vector3 colour;
  /// The distance along the ray at which the hit occurred
  double t;
  /// Whether the ray hit the front face of the object
  bool front_face;

  /**
   * @brief Sets the hit normal, flipping it to face against the ray
   *
   * @param r The ray that produced the hit
   * @param outwardNormal The outward-facing surface normal at the hit point
   */
  inline void SetFaceNormal(const Ray &r, const Vector3 &outwardNormal) {
    front_face = (r.Direction() & outwardNormal) < 0;
    normal = front_face ? outwardNormal : -outwardNormal;
  }
};

} // namespace photon
