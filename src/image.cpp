#include "photon/image.hpp"
#include <stdexcept>

photon::Image::Image(uint32_t width, uint32_t height)
    : data_(width * height, 0), width_(width), height_(height) {}

photon::Image::~Image() {}

void photon::Image::SetPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g,
                             uint8_t b) {
  if (x >= width_ || y >= height_)
    throw std::invalid_argument("x and y must be smaller than the image");

  uint64_t idx = static_cast<uint64_t>(y) * width_ + x;
  const uint32_t colour = (static_cast<uint32_t>(r) << 24) |
                          (static_cast<uint32_t>(g) << 16) |
                          (static_cast<uint32_t>(b) << 8);

  data_[idx] = colour;
}

void photon::Image::SetPixel(uint32_t x, uint32_t y, photon::Vector3 colour) {
  if (x >= width_ || y >= height_)
    throw std::invalid_argument("x and y must be smaller than the image");

  uint64_t idx = static_cast<uint64_t>(y) * width_ + x;
  const uint32_t colour_packed =
      (static_cast<uint32_t>(colour.X() * 255) << 24) |
      (static_cast<uint32_t>(colour.Y() * 255) << 16) |
      (static_cast<uint32_t>(colour.Z() * 255) << 8);

  data_[idx] = colour_packed;
}

uint32_t photon::Image::Width() const { return width_; }

uint32_t photon::Image::Height() const { return height_; }
