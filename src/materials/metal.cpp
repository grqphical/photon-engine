#include "photon/materials/metal.hpp"
#include "photon/ray.hpp"
#include "photon/ray_hit.hpp"
#include "photon/vector3.hpp"
#include <stdexcept>

namespace photon::materials {

Metal::Metal(const Vector3 &albedo, double fuzziness) : albedo(albedo) {
  if (fuzziness < 0 || fuzziness > 1)
    throw std::invalid_argument("fuzziness must be between 0.0 and 1.0");
  this->fuzziness = fuzziness;
}

bool Metal::Scatter(const photon::Ray &rayIn, const photon::RayHit &hitRecord,
                    photon::Vector3 &attenuation,
                    photon::Ray &scattered) const {

  Vector3 reflected = rayIn.Direction().Reflect(hitRecord.normal) +
                      (fuzziness * Vector3::RandomUnit());
  scattered = Ray(hitRecord.point, reflected);
  attenuation = albedo;
  return (scattered.Direction() & hitRecord.normal) > 0;
}

} // namespace photon::materials
