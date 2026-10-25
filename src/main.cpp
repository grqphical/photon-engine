
#include "raytracer/objects/sphere.hpp"
#include "raytracer/renderer.hpp"
#include "raytracer/vector3.hpp"
int main() {
  raytracer::Renderer renderer = raytracer::Renderer(16.0 / 9.0, 800);

  renderer.AddObject(std::make_unique<raytracer::objects::Sphere>(
      raytracer::Vector3(0.0, 0.0, -1.0), 0.5,
      raytracer::Vector3(1.0, 0.0, 0.0)));

  renderer.RenderToFile("render.ppm");

  return 0;
}
