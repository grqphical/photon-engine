#pragma once

#include "photon/camera.hpp"
#include "photon/image.hpp"
#include "photon/objects/object.hpp"
#include "photon/renderer_params.hpp"
#include "photon/scene.hpp"
#include <memory>
namespace photon {

/**
 * @brief Renders a scene to an image file
 */
class Renderer {
public:
  /**
   * @brief Constructs a renderer with the given aspect ratio and width
   *
   * @param aspectRatio The aspect ratio of the output image
   * @param outputImageWidth The width of the output image in pixels
   */
  Renderer(double aspectRatio, int outputImageWidth);

  /**
   * @brief Renders the scene and writes it to the given file
   *
   * @param filePath The path of the file to write the rendered image to
   * @param params Parameters controlling how the scene is rendered
   */
  void RenderToFile(std::string filePath, const photon::RendererParams &params);

  /**
   * @brief Adds an object to the rendered scene
   *
   * @param obj The object to add
   */
  void AddObject(std::shared_ptr<photon::objects::Object> obj);

private:
  double aspectRatio;
  Image output;
  Camera camera;
  Scene scene;

  /**
   * @brief Computes the colour of the pixel seen along a ray
   *
   * @param R The ray to trace
   * @param scene The scene to trace the ray against
   * @param params Parameters controlling how the scene is rendered
   *
   * @return The colour of the pixel as a vector with components in [0, 1]
   */
  Vector3 DetermineRayColour(const Ray &R, const Scene &scene,
                             const photon::RendererParams &params);
};

} // namespace photon
