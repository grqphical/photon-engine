#include "raytracer/renderer.hpp"
#include "raytracer/camera.hpp"
#include "raytracer/image_writer/ppm_writer.hpp"
#include "raytracer/ray.hpp"
#include "raytracer/vector3.hpp"

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
  std::cout << "Rendering scene...\n";
  for (uint32_t y = 0; y < output.Height(); y++) {
    std::cout << "\rScanlines Remaining: (" << y << "/" << output.Height()
              << ")" << std::flush;
    for (uint32_t x = 0; x < output.Width(); x++) {
      Vector3 pixelCenter = camera.TopLeftPixel() + (x * camera.PixelDeltaU()) +
                            (y * camera.PixelDeltaV());
      Vector3 raydirection = pixelCenter - camera.Position();

      Ray r(camera.Position(), raydirection);

      Vector3 pixelColour = GetRayColour(r);
      output.SetPixel(x, y, pixelColour);
    }
  }

  image_writer::PPMWriter writer;
  writer.SaveImage(output, filePath);
  std::cout << "\rDone.                     \n";
}
} // namespace raytracer
