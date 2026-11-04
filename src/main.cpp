
#include "photon/materials/lambertian.hpp"
#include "photon/objects/sphere.hpp"
#include "photon/renderer.hpp"
#include "photon/renderer_params.hpp"
#include "photon/vector3.hpp"
#include <memory>

int main() {
  photon::Renderer renderer = photon::Renderer(16.0 / 9.0, 1600);

  auto material_ground = std::make_shared<photon::materials::Lambertian>(
      photon::Vector3(0.8, 0.8, 0.0));

  renderer.AddObject(std::make_shared<photon::objects::Sphere>(
      photon::Vector3(0, 0, -1), 0.5, material_ground));
  renderer.AddObject(std::make_shared<photon::objects::Sphere>(
      photon::Vector3(0, -100.5, -1), 100, material_ground));

  renderer.RenderToFile("render.ppm", photon::RendererParams(false, 10, 50));

  return 0;
}
