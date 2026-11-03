#include "photon/camera.hpp"
#include "photon/interval.hpp"
#include "photon/photon.hpp"
#include "photon/renderer_params.hpp"
#include "photon/vector3.hpp"

namespace photon {

Camera::Camera(double focalLength, double viewportHeight,
               photon::Vector3 cameraCenter, int imageWidth, int imageHeight)
    : viewportHeight(viewportHeight), cameraCenter(cameraCenter) {

  viewportWidth =
      viewportHeight * (static_cast<double>(imageWidth) / imageHeight);

  viewportU = Vector3(viewportWidth, 0, 0);
  viewportV = Vector3(0, -viewportHeight, 0);

  pixelDeltaU = viewportU / imageWidth;
  pixelDeltaV = viewportV / imageHeight;

  viewportUpperLeft =
      cameraCenter - Vector3(0, 0, focalLength) - viewportU / 2 - viewportV / 2;
  pixel00Location = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);
}

const Vector3 &Camera::Position() const { return cameraCenter; }
const Vector3 &Camera::TopLeftPixel() const { return pixel00Location; }
const Vector3 &Camera::PixelDeltaU() const { return pixelDeltaU; }
const Vector3 &Camera::PixelDeltaV() const { return pixelDeltaV; }

Vector3 Camera::RayColour(const Ray &r, const Scene &scene,
                          const RendererParams &params, int depth) {
  if (depth <= 0)
    return Vector3(0.0, 0.0, 0.0);

  RayHit hit;

  if (scene.RayHit(r, Interval(0, infinity), hit)) {
    if (params.renderNormals) {
      return 0.5 * (hit.normal + Vector3(1.0, 1.0, 1.0));
    }

    Vector3 direction = Vector3::RandomOnHemisphere(hit.normal);
    return 0.5 * RayColour(Ray(hit.point, direction), scene, params, depth - 1);
  }

  Vector3 unitDirection = r.Direction().Unit();
  double a = 0.5 * (unitDirection.Y() + 1.0);
  return (1.0 - a) * Vector3(1.0, 1.0, 1.0) + a * Vector3(0.5, 0.7, 1.0);
}
} // namespace photon
