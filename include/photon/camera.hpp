#pragma once

#include "photon/vector3.hpp"
namespace photon {

/**
 * @brief Represents the camera rendering the current scene
 **/
class Camera {
public:
  /// Default constructs and empty camera
  Camera() {};

  /*
   * @brief Constructor for the Camera class
   *
   * @param focalLength Camera focal length
   * @param viewportHeight The maximum height in world space of the viewport
   * @param cameraCenter Where in the scene the camera should be placed
   * @param imageWidth The width of the output image in pixels
   * @param imageHeight The heigh of the output image in pixels
   */
  Camera(double focalLength, double viewportHeight,
         photon::Vector3 cameraCenter, int imageWidth, int imageHeight);

  /*
   * @brief Returns the camera's world position
   */
  const Vector3 &Position() const;
  /*
   * @brief Returns the top left pixel in 3D world space
   */
  const Vector3 &TopLeftPixel() const;
  /*
   * @brief Returns the horizontal pixel delta vector between rays
   */
  const Vector3 &PixelDeltaU() const;
  /*
   * @brief Returns the vertical pixel delta vector between rays
   */
  const Vector3 &PixelDeltaV() const;

private:
  double viewportHeight, viewportWidth;
  Vector3 cameraCenter;
  Vector3 viewportU, viewportV;
  Vector3 pixelDeltaU, pixelDeltaV;

  Vector3 viewportUpperLeft, pixel00Location;
};

} // namespace photon
