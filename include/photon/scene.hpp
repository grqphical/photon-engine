#pragma once

#include "photon/objects/object.hpp"
#include "photon/ray_hit.hpp"
#include <memory>
#include <vector>
namespace photon {

using photon::objects::Object;
class Scene {

public:
  Scene();
  ~Scene();

  void AddObject(std::shared_ptr<Object> obj);
  void Clear();
  bool RayHit(const Ray &r, double ray_min, double ray_max, RayHit &hit) const;

private:
  std::vector<std::shared_ptr<Object>> objects;
};

} // namespace photon
