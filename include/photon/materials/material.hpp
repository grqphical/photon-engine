#pragma once

namespace photon::materials {
class Material {
public:
  virtual ~Material() = default;

  virtual bool Scatter();
};
} // namespace photon::materials
