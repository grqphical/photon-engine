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

  std::cout << "Rendering scene...\n";
  auto start = high_resolution_clock::now();

  for (uint32_t y = 0; y < output.Height(); y++) {
    for (uint32_t x = 0; x < output.Width(); x++) {
      Vector3 pixelCenter = camera.TopLeftPixel() + (x * camera.PixelDeltaU()) +
                            (y * camera.PixelDeltaV());
      Vector3 raydirection = pixelCenter - camera.Position();

      Ray r(camera.Position(), raydirection);

      Vector3 pixelColour = DetermineRayColour(r, scene, params);
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

void Renderer::AddObject(std::shared_ptr<photon::objects::Object> obj) {
  scene.AddObject(obj);
}

Vector3 Renderer::DetermineRayColour(const Ray &r, const Scene &scene,
                                     const RendererParams &params) {
  photon::RayHit hit;
  if (scene.RayHit(r, 0, photon::INFINITY, hit)) {
    if (params.renderNormals)
      return 0.5 * (hit.normal + Vector3(1.0, 1.0, 1.0));
    return hit.colour;
  }

  Vector3 unitDirection = r.Direction().Unit();
  auto a = 0.5 * (unitDirection.Y() + 1.0);
  return (1.0 - a) * Vector3(1.0, 1.0, 1.0) + a * Vector3(0.5, 0.7, 1.0);
}

} // namespace photon
