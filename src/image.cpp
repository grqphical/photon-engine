#include "raytracer/image.hpp"
#include <stdexcept>

raytracer::Image::Image(uint32_t width, uint32_t height)
    : data_(width * height, 0), width_(width), height_(height) {}

raytracer::Image::~Image() {}

void raytracer::Image::SetPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g,
                                uint8_t b) {
  if (x >= width_ || y >= height_)
    throw std::invalid_argument("x and y must be smaller than the image");

  uint64_t idx = static_cast<uint64_t>(y) * width_ + x;
  const uint32_t colour = (static_cast<uint32_t>(r) << 24) |
                          (static_cast<uint32_t>(g) << 16) |
                          (static_cast<uint32_t>(b) << 8);

  data_[idx] = colour;
}

void raytracer::Image::SetPixel(uint32_t x, uint32_t y,
                                raytracer::Vector3 colour) {
  if (x >= width_ || y >= height_)
    throw std::invalid_argument("x and y must be smaller than the image");

  uint64_t idx = static_cast<uint64_t>(y) * width_ + x;
  const uint32_t colour_packed =
      (static_cast<uint32_t>(colour.X() * 255) << 24) |
      (static_cast<uint32_t>(colour.Y() * 255) << 16) |
      (static_cast<uint32_t>(colour.Z() * 255) << 8);

  data_[idx] = colour_packed;
}

uint32_t raytracer::Image::Width() const { return width_; }

uint32_t raytracer::Image::Height() const { return height_; }
