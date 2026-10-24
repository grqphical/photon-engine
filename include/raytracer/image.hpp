#pragma once
#include "raytracer/vector3.hpp"
#include <cstdint>
#include <vector>

namespace raytracer {
// represents a 2D image, used to output rendered scenes. Colour data is stored
// as 0xRRGGBB00
class Image {
  using iterator = std::vector<uint32_t>::iterator;
  using const_iterator = std::vector<uint32_t>::const_iterator;

public:
  Image(uint32_t width, uint32_t height);
  ~Image();

  iterator Begin() { return data_.begin(); }
  iterator End() { return data_.end(); }

  const_iterator Begin() const { return data_.begin(); }
  const_iterator End() const { return data_.end(); }

  const_iterator CBegin() const { return data_.cbegin(); }
  const_iterator CEnd() const { return data_.cend(); }

  void SetPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b);
  void SetPixel(uint32_t x, uint32_t y, raytracer::Vector3 colour);

  uint32_t Width() const;
  uint32_t Height() const;

private:
  std::vector<uint32_t> data_;
  uint32_t width_, height_;
};
} // namespace raytracer
