#pragma once

#include "photon/objects/object.hpp"
#include "photon/ray_hit.hpp"
#include <memory>
#include <vector>
namespace photon {

using photon::objects::Object;
/**
 * @brief Holds the objects that make up a scene
 */
class Scene {

public:
  /// Constructs an empty scene
  Scene();
  /// Destroys the scene and its objects
  ~Scene();

  /**
   * @brief Adds an object to the scene
   *
   * @param obj The object to add
   */
  void AddObject(std::shared_ptr<Object> obj);

  /// Removes all objects from the scene
  void Clear();

  /**
   * @brief Finds the closest object hit by a ray within a distance range
   *
   * @param r The ray to trace
   * @param ray_min The minimum distance along the ray to consider
   * @param ray_max The maximum distance along the ray to consider
   * @param hit Filled with details of the closest hit
   *
   * @return true if the ray hits any object within the given range
   */
  bool RayHit(const Ray &r, double ray_min, double ray_max, RayHit &hit) const;

private:
  std::vector<std::shared_ptr<Object>> objects;
};

} // namespace photon
