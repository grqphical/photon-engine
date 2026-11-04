#pragma once

namespace photon {
class Ray;
class RayHit;
class Vector3;
} // namespace photon
namespace photon::materials {
class Material {
public:
  virtual ~Material() = default;

  virtual bool Scatter(const photon::Ray &rayIn,
                       const photon::RayHit &hitRecord,
                       photon::Vector3 &attenuation,
                       photon::Ray &scattered) const = 0;
};
} // namespace photon::materials
