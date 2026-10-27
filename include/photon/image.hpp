#pragma once
#include "photon/vector3.hpp"
#include <cstdint>
#include <vector>

namespace photon {
/**
 * @brief Represents a 2D image, used to output rendered scenes
 *
 * @note Colour data is stored as 32 bit unsigned integers in the form
 * 0xRRGGBB00 (no alpha)
 */
class Image {
  /// Mutable iterator over the packed pixel data
  using iterator = std::vector<uint32_t>::iterator;
  /// Read-only iterator over the packed pixel data
  using const_iterator = std::vector<uint32_t>::const_iterator;

public:
  /// Default constructs an empty image
  inline Image() {};

  /**
   * @brief Constructs an image of the given dimensions filled with black
   *
   * @param width The width of the image in pixels
   * @param height The height of the image in pixels
   */
  Image(uint32_t width, uint32_t height);

  /// Destroys the image, releasing its pixel data
  ~Image();

  /// Returns an iterator to the first pixel
  iterator Begin() { return data_.begin(); }
  /// Returns an iterator past the last pixel
  iterator End() { return data_.end(); }

  /// Returns a read-only iterator to the first pixel
  const_iterator Begin() const { return data_.begin(); }
  /// Returns a read-only iterator past the last pixel
  const_iterator End() const { return data_.end(); }

  /// Returns a read-only iterator to the first pixel
  const_iterator CBegin() const { return data_.cbegin(); }
  /// Returns a read-only iterator past the last pixel
  const_iterator CEnd() const { return data_.cend(); }

  /**
   * @brief Sets the colour of the pixel at the given coordinates
   *
   * @param x The horizontal pixel coordinate
   * @param y The vertical pixel coordinate
   * @param r The red channel value (0-255)
   * @param g The green channel value (0-255)
   * @param b The blue channel value (0-255)
   *
   * @throws std::invalid_argument If the coordinates are outside the image
   */
  void SetPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b);

  /**
   * @brief Sets the colour of the pixel at the given coordinates
   *
   * @param x The horizontal pixel coordinate
   * @param y The vertical pixel coordinate
   * @param colour The colour as a vector with components in the range [0, 1]
   *
   * @throws std::invalid_argument If the coordinates are outside the image
   */
  void SetPixel(uint32_t x, uint32_t y, photon::Vector3 colour);

  /// Returns the width of the image in pixels
  uint32_t Width() const;
  /// Returns the height of the image in pixels
  uint32_t Height() const;

private:
  std::vector<uint32_t> data_;
  uint32_t width_, height_;
};
} // namespace photon
