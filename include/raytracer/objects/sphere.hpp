#pragma once

#include "raytracer/objects/object.hpp"
#include "raytracer/ray.hpp"
#include "raytracer/vector3.hpp"

namespace raytracer::objects {
class Sphere : public Object {
public:
  Sphere(Vector3 center, double radius, Vector3 colour);

  bool RayHit(const Ray &r) const;
  Vector3 GetSurfaceColour() const;

private:
  Vector3 center, colour;
  double radius;
};
} // namespace raytracer::objects
