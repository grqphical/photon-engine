#include "photon/camera.hpp"
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

} // namespace photon
