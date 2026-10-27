#pragma once

#include "photon/objects/object.hpp"
#include "photon/ray.hpp"
#include "photon/vector3.hpp"

namespace photon::objects {
class Sphere : public Object {
public:
  Sphere(Vector3 center, double radius, Vector3 colour);

  bool RayHit(const Ray &r, double ray_min, double ray_max,
              photon::RayHit &result) const;

private:
  Vector3 center, colour;
  double radius;
};
} // namespace photon::objects
