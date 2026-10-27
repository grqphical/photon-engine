#pragma once

#include "photon/ray.hpp"
#include "photon/ray_hit.hpp"

namespace photon::objects {
/**
 * @brief Base class for all objects that can be placed in a scene
 */
class Object {
public:
  /// Destroys the object
  virtual ~Object() = default;

  /**
   * @brief Tests whether a ray intersects this object
   *
   * @param r The ray to test against
   * @param ray_min The minimum distance along the ray to consider
   * @param ray_max The maximum distance along the ray to consider
   * @param result Filled with details of the hit when the ray intersects
   *
   * @return true if the ray intersects the object within the given range
   */
  virtual bool RayHit(const Ray &r, double ray_min, double ray_max,
                      photon::RayHit &result) const = 0;
};
} // namespace photon::objects
