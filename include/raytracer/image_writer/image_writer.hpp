#pragma once
#include "raytracer/image.hpp"
#include <cstdint>
#include <string>

namespace raytracer::image_writer {

// A base class to save images in a variety of formats
class ImageWriter {
public:
  // Writes a vector of image data to the given output_file
  virtual void SaveImage(raytracer::Image &image, uint32_t width,
                         uint32_t height, std::string output_file) = 0;
};
} // namespace raytracer::image_writer
