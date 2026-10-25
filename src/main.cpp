
#include "photon/objects/sphere.hpp"
#include "photon/renderer.hpp"
#include "photon/vector3.hpp"
int main() {
  photon::Renderer renderer = photon::Renderer(16.0 / 9.0, 800);

  renderer.AddObject(std::make_unique<photon::objects::Sphere>(
      photon::Vector3(0.0, 0.0, -1.0), 0.5, photon::Vector3(1.0, 0.0, 0.0)));

  renderer.RenderToFile("render.ppm");

  return 0;
}
