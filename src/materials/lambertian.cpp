#include "photon/materials/lambertian.hpp"
#include "photon/ray.hpp"
#include "photon/vector3.hpp"

namespace photon::materials {

Lambertian::Lambertian(const photon::Vector3 &albedo) : albedo(albedo) {}

bool Lambertian::Scatter(const photon::Ray &rayIn,
                         const photon::RayHit &hitRecord,
                         photon::Vector3 &attentuation,
                         photon::Ray &scattered) const {
  auto scatterDirection = hitRecord.normal + Vector3::RandomUnit();
  scattered = Ray(hitRecord.point, scatterDirection);
  attentuation = albedo;
  return true;
}

} // namespace photon::materials
