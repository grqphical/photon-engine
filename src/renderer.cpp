#include "photon/renderer.hpp"
#include "photon/camera.hpp"
#include "photon/image_writer/ppm_writer.hpp"
#include "photon/objects/object.hpp"
#include "photon/photon.hpp"
#include "photon/ray.hpp"
#include "photon/vector3.hpp"

#include <chrono>
#include <iostream>
#include <memory>

namespace photon {
using photon::objects::Object;

Renderer::Renderer(double aspectRatio, int outputImageWidth)
    : aspectRatio(aspectRatio) {
  int outputImageHeight = int(outputImageWidth / aspectRatio);
  outputImageHeight = (outputImageHeight < 1) ? 1 : outputImageHeight;

  camera =
      Camera(1.0, 2.0, Vector3(0, 0, 0), outputImageWidth, outputImageHeight);
  output = Image(outputImageWidth, outputImageHeight);
}

void Renderer::RenderToFile(std::string filePath,
                            const RendererParams &params) {
  using std::chrono::duration;
  using std::chrono::duration_cast;
  using std::chrono::high_resolution_clock;
  using std::chrono::milliseconds;

  double sampleScale = 1.0 / params.samplesPerPixel;

  std::cout << "Rendering scene...\n";
  auto start = high_resolution_clock::now();

  for (uint32_t y = 0; y < output.Height(); y++) {
    for (uint32_t x = 0; x < output.Width(); x++) {
      Vector3 pixelColour(0, 0, 0);

      for (int i = 0; i < params.samplesPerPixel; i++) {
        Ray r = GetRay(x, y);
        pixelColour += camera.RayColour(r, scene, params);
      }

      output.SetPixel(x, y, pixelColour * sampleScale);
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

void Renderer::AddObject(std::shared_ptr<photon::objects::Object> obj) {
  scene.AddObject(obj);
}

Ray Renderer::GetRay(int x, int y) const {
  Vector3 offset = SampleSquare();
  Vector3 pixelCenter = camera.TopLeftPixel() +
                        ((x + offset.X()) * camera.PixelDeltaU()) +
                        ((y + offset.Y()) * camera.PixelDeltaV());

  Vector3 raydirection = pixelCenter - camera.Position();
  return Ray(camera.Position(), raydirection);
}

Vector3 Renderer::SampleSquare() const {
  return Vector3(RandomDouble() - 0.5, RandomDouble() - 0.5, 0);
}

} // namespace photon
