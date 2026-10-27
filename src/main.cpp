
#include "photon/objects/sphere.hpp"
#include "photon/renderer.hpp"
#include "photon/renderer_params.hpp"
#include "photon/vector3.hpp"
int main() {
  photon::Renderer renderer = photon::Renderer(16.0 / 9.0, 800);

  renderer.AddObject(std::make_shared<photon::objects::Sphere>(
      photon::Vector3(0, 0, -1), 0.5, photon::Vector3(1.0, 0.0, 0.0)));
  renderer.AddObject(std::make_shared<photon::objects::Sphere>(
      photon::Vector3(0, -100.5, -1), 100, photon::Vector3(0.0, 1.0, 0.0)));

  renderer.RenderToFile("render.ppm", photon::RendererParams(true));

  return 0;
}
