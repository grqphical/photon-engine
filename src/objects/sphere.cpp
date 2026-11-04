#include "photon/objects/sphere.hpp"
#include "photon/interval.hpp"
#include "photon/materials/material.hpp"
#include "photon/ray.hpp"
#include "photon/vector3.hpp"
#include <cmath>

namespace photon::objects {

Sphere::Sphere(Vector3 center, double radius,
               std::shared_ptr<materials::Material> material)
    : center(center), radius(radius), material(material) {}

bool Sphere::RayHit(const Ray &r, photon::Interval rayRange,
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
  if (!rayRange.Surrounds(root)) {
    root = (h + sqrtd) / a;
    if (!rayRange.Surrounds(root))
      return false;
  }

  result.t = root;
  result.point = r.At(result.t);
  Vector3 outwardNormal = (result.point - center) / radius;
  result.SetFaceNormal(r, outwardNormal);
  result.material = material;

  return true;
}

} // namespace photon::objects
