#pragma once

#include "raytracer/camera.hpp"
#include "raytracer/image.hpp"
#include "raytracer/ray.hpp"
namespace raytracer {

class Renderer {
public:
  Renderer(double aspectRatio, int outputImageWidth);

  void RenderToFile(std::string filePath);

private:
  double aspectRatio;
  Image output;
  Camera camera;

  Vector3 GetRayColour(const Ray &ray) const;
};

} // namespace raytracer
