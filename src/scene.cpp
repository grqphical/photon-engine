#include "photon/scene.hpp"
#include "photon/interval.hpp"
#include "photon/ray_hit.hpp"

namespace photon {

Scene::Scene() {}
Scene::~Scene() {}

void Scene::AddObject(std::shared_ptr<Object> obj) { objects.push_back(obj); }

void Scene::Clear() { objects.clear(); }

bool Scene::RayHit(const Ray &r, Interval rayRange, photon::RayHit &hit) const {
  photon::RayHit currentHit;
  bool hitSomething = false;
  double closestHit = rayRange.Max();

  for (const auto &object : objects) {
    if (object->RayHit(r, Interval(rayRange.Min(), closestHit), currentHit)) {
      hitSomething = true;
      closestHit = currentHit.t;
      hit = currentHit;
    }
  }

  return hitSomething;
}

} // namespace photon
