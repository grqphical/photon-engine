#pragma once

#include "photon/ray.hpp"
#include "photon/vector3.hpp"

namespace photon::objects {
class Object {
public:
  virtual ~Object() = default;
  virtual bool RayHit(const Ray &r) const = 0;
  virtual Vector3 GetSurfaceColour() const = 0;
};
} // namespace photon::objects
