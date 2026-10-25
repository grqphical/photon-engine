#pragma once

#include "raytracer/ray.hpp"
#include "raytracer/vector3.hpp"

namespace raytracer::objects {
class Object {
public:
  virtual ~Object() = default;
  virtual bool RayHit(const Ray &r) const = 0;
  virtual Vector3 GetSurfaceColour() const = 0;
};
} // namespace raytracer::objects
