#pragma once

#include "photon/camera.hpp"
#include "photon/image.hpp"
#include "photon/objects/object.hpp"
#include <memory>
namespace photon {

class Renderer {
public:
  Renderer(double aspectRatio, int outputImageWidth);

  void RenderToFile(std::string filePath);
  void AddObject(std::unique_ptr<photon::objects::Object> obj);

private:
  double aspectRatio;
  Image output;
  Camera camera;
  std::vector<std::unique_ptr<photon::objects::Object>> objects;
};

} // namespace photon
