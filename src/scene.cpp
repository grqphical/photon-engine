#include "photon/scene.hpp"
#include "photon/ray_hit.hpp"

namespace photon {

Scene::Scene() {}
Scene::~Scene() {}

void Scene::AddObject(std::shared_ptr<Object> obj) { objects.push_back(obj); }

void Scene::Clear() { objects.clear(); }

bool Scene::RayHit(const Ray &r, double ray_min, double ray_max,
                   photon::RayHit &hit) const {
  photon::RayHit currentHit;
  bool hitSomething = false;
  double closestHit = ray_max;

  for (const auto &object : objects) {
    if (object->RayHit(r, ray_min, closestHit, currentHit)) {
      hitSomething = true;
      closestHit = currentHit.t;
      hit = currentHit;
    }
  }

  return hitSomething;
}

} // namespace photon
