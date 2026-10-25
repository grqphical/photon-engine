#pragma once

#include "raytracer/ray.hpp"
#include "raytracer/vector3.hpp"

namespace raytracer::objects {
class Object {
public:
  virtual bool RayHit(const Ray &r) = 0;
  virtual Vector3 GetSurfaceColour() = 0;
};
} // namespace raytracer::objects
