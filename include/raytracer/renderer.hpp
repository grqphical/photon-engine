#pragma once

#include "raytracer/camera.hpp"
#include "raytracer/image.hpp"
#include "raytracer/objects/object.hpp"
#include "raytracer/ray.hpp"
#include <memory>
namespace raytracer {

class Renderer {
public:
  Renderer(double aspectRatio, int outputImageWidth);

  void RenderToFile(std::string filePath);
  void AddObject(std::unique_ptr<raytracer::objects::Object> obj);

private:
  double aspectRatio;
  Image output;
  Camera camera;
  std::vector<std::unique_ptr<raytracer::objects::Object>> objects;

  Vector3 GetRayColour(const Ray &ray) const;
};

} // namespace raytracer
