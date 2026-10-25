#include "raytracer/renderer.hpp"
#include "raytracer/camera.hpp"
#include "raytracer/image_writer/ppm_writer.hpp"
#include "raytracer/ray.hpp"
#include "raytracer/vector3.hpp"

#include <chrono>
#include <iostream>

namespace raytracer {

Renderer::Renderer(double aspectRatio, int outputImageWidth)
    : aspectRatio(aspectRatio) {
  int outputImageHeight = int(outputImageWidth / aspectRatio);
  outputImageHeight = (outputImageHeight < 1) ? 1 : outputImageHeight;

  camera =
      Camera(1.0, 2.0, Vector3(0, 0, 0), outputImageWidth, outputImageHeight);
  output = Image(outputImageWidth, outputImageHeight);
}

Vector3 Renderer::GetRayColour(const Ray &r) const {
  Vector3 unitDirection = r.Direction().Unit();
  auto a = 0.5 * (unitDirection.Y() + 1.0);
  return (1.0 - a) * Vector3(1.0, 1.0, 1.0) + a * Vector3(0.5, 0.7, 1.0);
}

void Renderer::RenderToFile(std::string filePath) {
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  std::cout << "Rendering scene...\n";
  auto start = high_resolution_clock::now();

  for (uint32_t y = 0; y < output.Height(); y++) {
    for (uint32_t x = 0; x < output.Width(); x++) {
      Vector3 pixelCenter = camera.TopLeftPixel() + (x * camera.PixelDeltaU()) +
                            (y * camera.PixelDeltaV());
      Vector3 raydirection = pixelCenter - camera.Position();

      Ray r(camera.Position(), raydirection);

      Vector3 pixelColour = GetRayColour(r);
      output.SetPixel(x, y, pixelColour);
    }
    std::cout << "\rScanlines Rendered: (" << y + 1 << "/" << output.Height()
              << ")" << std::flush;
  }
  auto end = high_resolution_clock::now();
  auto msInt = duration_cast<milliseconds>(end - start);

  image_writer::PPMWriter writer;
  writer.SaveImage(output, filePath);
  std::cout << "\nDone in " << msInt << "\n";
}
} // namespace raytracer
