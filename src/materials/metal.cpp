#include "photon/materials/metal.hpp"
#include "photon/ray.hpp"
#include "photon/ray_hit.hpp"
#include "photon/vector3.hpp"

namespace photon::materials {

Metal::Metal(const Vector3 &albedo) : albedo(albedo) {}

bool Metal::Scatter(const photon::Ray &rayIn, const photon::RayHit &hitRecord,
                    photon::Vector3 &attenuation,
                    photon::Ray &scattered) const {

  Vector3 reflected = rayIn.Direction().Reflect(hitRecord.normal);
  scattered = Ray(hitRecord.point, reflected);
  attenuation = albedo;
  return true;
}

} // namespace photon::materials
