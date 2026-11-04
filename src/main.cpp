
#include "photon/materials/lambertian.hpp"
#include "photon/materials/metal.hpp"
#include "photon/objects/sphere.hpp"
#include "photon/renderer.hpp"
#include "photon/renderer_params.hpp"
#include "photon/vector3.hpp"
#include <memory>

int main() {
  photon::Renderer renderer = photon::Renderer(16.0 / 9.0, 1600);

  auto material_ground = std::make_shared<photon::materials::Lambertian>(
      photon::Vector3(0.8, 0.8, 0.0));
  auto material_center = std::make_shared<photon::materials::Lambertian>(
      photon::Vector3(0.1, 0.2, 0.5));
  auto material_left = std::make_shared<photon::materials::Metal>(
      photon::Vector3(0.8, 0.8, 0.8));
  auto material_right = std::make_shared<photon::materials::Metal>(
      photon::Vector3(0.8, 0.6, 0.2));

  renderer.AddObject(std::make_shared<photon::objects::Sphere>(
      photon::Vector3(0, -100.5, -1), 100, material_ground));

  renderer.AddObject(std::make_shared<photon::objects::Sphere>(
      photon::Vector3(0, 0.0, -1.2), 0.5, material_center));

  renderer.AddObject(std::make_shared<photon::objects::Sphere>(
      photon::Vector3(-1.0, 0.0, -1.0), 0.5, material_left));

  renderer.AddObject(std::make_shared<photon::objects::Sphere>(
      photon::Vector3(1.0, 0.0, -1.0), 0.5, material_right));

  renderer.RenderToFile("render.ppm", photon::RendererParams(false, 10, 50));

  return 0;
}
