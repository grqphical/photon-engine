#pragma once

#include "photon/camera.hpp"
#include "photon/image.hpp"
#include "photon/objects/object.hpp"
#include "photon/scene.hpp"
#include <memory>
namespace photon {

class Renderer {
public:
  Renderer(double aspectRatio, int outputImageWidth);

  void RenderToFile(std::string filePath);
  void AddObject(std::shared_ptr<photon::objects::Object> obj);

private:
  double aspectRatio;
  Image output;
  Camera camera;
  Scene scene;

  Vector3 DetermineRayColour(const Ray &R, const Scene &scene);
};

} // namespace photon
