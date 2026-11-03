#pragma once

namespace photon {

/**
 * @brief Parameters controlling how a scene is rendered
 */
struct RendererParams {
  /// When true, surfaces are shaded by their normal instead of their colour
  bool renderNormals;

  /// How many samples per pixel should be taken for anti-aliasing
  int samplesPerPixel = 10;
  
  /// The maximum number of light bounces a ray can do after hitting a surface
  int maxBounces = 10;
};

} // namespace photon
