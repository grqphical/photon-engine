
#include "raytracer/renderer.hpp"
int main() {
  raytracer::Renderer renderer = raytracer::Renderer(16.0 / 9.0, 400);

  renderer.RenderToFile("render.ppm");

  return 0;
}
