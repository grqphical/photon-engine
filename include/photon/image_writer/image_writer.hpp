#pragma once
#include "photon/image.hpp"
#include <cstdint>
#include <string>

namespace photon::image_writer {

// A base class to save images in a variety of formats
class ImageWriter {
public:
  // Writes a vector of image data to the given output_file
  virtual void SaveImage(photon::Image &image, std::string output_file) = 0;
};
} // namespace photon::image_writer
