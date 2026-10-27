#pragma once

#include "photon/camera.hpp"
#include "photon/image.hpp"
#include "photon/objects/object.hpp"
#include "photon/renderer_params.hpp"
#include "photon/scene.hpp"
#include <memory>
namespace photon {

class Renderer {
public:
  Renderer(double aspectRatio, int outputImageWidth);

  void RenderToFile(std::string filePath, const photon::RendererParams &params);
  void AddObject(std::shared_ptr<photon::objects::Object> obj);

private:
  double aspectRatio;
  Image output;
  Camera camera;
  Scene scene;

  Vector3 DetermineRayColour(const Ray &R, const Scene &scene,
                             const photon::RendererParams &params);
};

} // namespace photon
