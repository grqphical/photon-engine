#pragma once

#include "photon/materials/material.hpp"
#include "photon/ray.hpp"
#include "vector3.hpp"
#include <memory>
namespace photon {
using photon::materials::Material;

/**
 * @brief Describes the intersection of a ray with an object
 */
class RayHit {

public:
  /// The point in world space where the ray hit the object
  Vector3 point;
  /// The surface normal at the hit point, oriented against the ray
  Vector3 normal;
  /// The distance along the ray at which the hit occurred
  double t;
  /// Whether the ray hit the front face of the object
  bool front_face;
  /// The material of the hit object
  std::shared_ptr<Material> material;

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
