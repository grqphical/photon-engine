#include "photon/objects/sphere.hpp"
#include "photon/ray.hpp"
#include "photon/vector3.hpp"
#include <cmath>

namespace photon::objects {

Sphere::Sphere(Vector3 center, double radius, Vector3 colour)
    : center(center), colour(colour), radius(radius) {}

bool Sphere::RayHit(const Ray &r, double ray_min, double ray_max,
                    photon::RayHit &result) const {
  Vector3 oc = center - r.Origin();
  double a = r.Direction().LengthSquared();
  double h = r.Direction() & oc;
  double c = oc.LengthSquared() - radius * radius;

  double discriminant = h * h - a * c;
  if (discriminant < 0.0)
    return false;

  double sqrtd = std::sqrt(discriminant);

  auto root = (h - sqrtd) / a;
  if (root <= ray_min || ray_max <= root) {
    root = (h + sqrtd) / a;
    if (root <= ray_min || ray_max <= root)
      return false;
  }

  result.t = root;
  result.point = r.At(result.t);
  Vector3 outwardNormal = (result.point - center) / radius;
  result.SetFaceNormal(r, outwardNormal);

  return true;
}

} // namespace photon::objects
