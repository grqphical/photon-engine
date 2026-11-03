#pragma once

#include "photon/renderer_params.hpp"
#include "photon/scene.hpp"
#include "photon/vector3.hpp"
namespace photon {

/**
 * @brief Represents the camera rendering the current scene
 **/
class Camera {
public:
  /// Default constructs an empty camera
  Camera() {};

  /**
   * @brief Constructs a camera for a given viewport and output resolution
   *
   * @param focalLength Camera focal length
   * @param viewportHeight The maximum height in world space of the viewport
   * @param cameraCenter Where in the scene the camera should be placed
   * @param imageWidth The width of the output image in pixels
   * @param imageHeight The height of the output image in pixels
   */
  Camera(double focalLength, double viewportHeight,
         photon::Vector3 cameraCenter, int imageWidth, int imageHeight);

  /**
   * @brief Returns the camera's world position
   */
  const Vector3 &Position() const;

  /**
   * @brief Returns the top left pixel in 3D world space
   */
  const Vector3 &TopLeftPixel() const;

  /**
   * @brief Returns the horizontal pixel delta vector between rays
   */
  const Vector3 &PixelDeltaU() const;

  /**
   * @brief Returns the vertical pixel delta vector between rays
   */
  const Vector3 &PixelDeltaV() const;

  /**
   * @brief Computes the colour of the pixel seen along a ray
   *
   * @param R The ray to trace
   * @param scene The scene to trace the ray against
   * @param params Parameters controlling how the scene is rendered
   *
   * @return The colour of the pixel as a vector with components in [0, 1]
   */
  Vector3 RayColour(const Ray &r, const Scene &scene,
                    const RendererParams &params, int depth);

private:
  double viewportHeight, viewportWidth;
  Vector3 cameraCenter;
  Vector3 viewportU, viewportV;
  Vector3 pixelDeltaU, pixelDeltaV;

  Vector3 viewportUpperLeft, pixel00Location;
};

} // namespace photon
