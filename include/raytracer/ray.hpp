#pragma once

#include "raytracer/vector3.hpp"
namespace raytracer {
class Ray {
public:
  Ray();
  Ray(const Vector3 &origin, const Vector3 &direction);

  const Vector3 &Origin() const;
  const Vector3 &Direction() const;

  Vector3 At(double t);

private:
  Vector3 origin, direction;
};
} // namespace raytracer
