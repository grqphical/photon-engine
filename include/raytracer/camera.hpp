#pragma once

#include "raytracer/vector3.hpp"
namespace raytracer {

class Camera {
public:
  Camera() {};
  Camera(double focalLength, double viewportHeight,
         raytracer::Vector3 cameraCenter, int imageWidth, int imageHeight);

  const Vector3 &Position() const;
  const Vector3 &TopLeftPixel() const;
  const Vector3 &PixelDeltaU() const;
  const Vector3 &PixelDeltaV() const;

private:
  double viewportHeight, viewportWidth;
  Vector3 cameraCenter;
  Vector3 viewportU, viewportV;
  Vector3 pixelDeltaU, pixelDeltaV;

  Vector3 viewportUpperLeft, pixel00Location;
};

} // namespace raytracer
