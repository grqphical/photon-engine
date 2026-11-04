#pragma once
#include "material.hpp"
#include "photon/ray.hpp"
#include "photon/ray_hit.hpp"
#include "photon/vector3.hpp"

namespace photon::materials {
class Lambertian : public Material {
public:
  Lambertian(const photon::Vector3 &albedo);

  bool Scatter(const photon::Ray &rayIn, const photon::RayHit &hitRecord,
               photon::Vector3 &attenuation, photon::Ray &scattered) const;

private:
  Vector3 albedo;
};
} // namespace photon::materials
