#pragma once

#include "photon/interval.hpp"
#include "photon/materials/material.hpp"
#include "photon/objects/object.hpp"
#include "photon/ray.hpp"
#include "photon/vector3.hpp"

namespace photon::objects {
/**
 * @brief A sphere object that can be rendered in a scene
 */
class Sphere : public Object {
public:
  /**
   * @brief Constructs a sphere
   *
   * @param center The centre of the sphere in world space
   * @param radius The radius of the sphere
   * @param colour The colour of the sphere
   */
  Sphere(Vector3 center, double radius,
         std::shared_ptr<materials::Material> material);

  /**
   * @brief Tests whether a ray intersects this sphere
   *
   * @param r The ray to test against
   * @param ray_min The minimum distance along the ray to consider
   * @param ray_max The maximum distance along the ray to consider
   * @param result Filled with details of the hit when the ray intersects
   *
   * @return true if the ray intersects the sphere within the given range
   */
  bool RayHit(const Ray &r, photon::Interval rayRange,
              photon::RayHit &result) const;

private:
  Vector3 center;
  double radius;
  std::shared_ptr<materials::Material> material;
};
} // namespace photon::objects
