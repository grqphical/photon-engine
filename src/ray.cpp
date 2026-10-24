#include "raytracer/ray.hpp"

namespace raytracer {

Ray::Ray() {}
Ray::Ray(const Vector3 &origin, const Vector3 &direction)
    : origin(origin), direction(direction) {}

const Vector3 &Ray::Origin() const { return origin; }

const Vector3 &Ray::Direction() const { return direction; }

Vector3 Ray::At(double t) { return origin + t * direction; }

} // namespace raytracer
