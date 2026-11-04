#pragma once

#include "photon/materials/material.hpp"
#include "photon/vector3.hpp"
namespace photon::materials {

class Metal : public Material {
public:
  Metal(const Vector3 &albedo, double fuzziness);
  bool Scatter(const photon::Ray &rayIn, const photon::RayHit &hitRecord,
               photon::Vector3 &attenuation,
               photon::Ray &scattered) const override;

private:
  Vector3 albedo;
  double fuzziness;
};

} // namespace photon::materials
