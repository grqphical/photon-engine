#pragma once

#include "photon/ray.hpp"
#include "photon/ray_hit.hpp"

namespace photon::objects {
class Object {
public:
  virtual ~Object() = default;
  virtual bool RayHit(const Ray &r, double ray_min, double ray_max,
                      photon::RayHit &result) const = 0;
};
} // namespace photon::objects
