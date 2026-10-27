#pragma once

#include "photon/ray.hpp"
#include "vector3.hpp"
namespace photon {

class RayHit {
public:
  Vector3 point;
  Vector3 normal;
  double t;
  bool front_face;

  inline void SetFaceNormal(const Ray &r, const Vector3 &outwardNormal) {
    front_face = (r.Direction() & outwardNormal) < 0;
    normal = front_face ? outwardNormal : -outwardNormal;
  }
};

} // namespace photon
