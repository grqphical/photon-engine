#pragma once
#include "photon/image.hpp"
#include <cstdint>
#include <string>

namespace photon::image_writer {

/**
 * @brief A base class to save images in a variety of formats
 */
class ImageWriter {
public:
  /**
   * @brief Writes an image to the given output file
   *
   * @param image The image to save
   * @param output_file The path of the file to write to
   */
  virtual void SaveImage(photon::Image &image, std::string output_file) = 0;
};
} // namespace photon::image_writer
