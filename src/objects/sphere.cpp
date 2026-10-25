#include "photon/objects/sphere.hpp"
#include "photon/ray.hpp"
#include "photon/vector3.hpp"

namespace photon::objects {

Sphere::Sphere(Vector3 center, double radius, Vector3 colour)
    : center(center), colour(colour), radius(radius) {}

bool Sphere::RayHit(const Ray &r) const {
  Vector3 oc = center - r.Origin();
  double a = r.Direction() & r.Direction();
  double b = -2.0 * (r.Direction() & oc);
  double c = (oc & oc) - radius * radius;

  double discriminant = b * b - 4 * a * c;
  return discriminant >= 0;
}

Vector3 Sphere::GetSurfaceColour() const {
  // for now just return a single colour, will add shading later
  return colour;
}

} // namespace photon::objects
