#pragma once

namespace photon {

/**
 * @brief Parameters controlling how a scene is rendered
 */
struct RendererParams {
  /// When true, surfaces are shaded by their normal instead of their colour
  bool renderNormals;
};

} // namespace photon
