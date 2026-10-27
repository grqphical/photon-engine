#pragma once

#include "photon/image.hpp"
#include "photon/image_writer/image_writer.hpp"

namespace photon::image_writer {
/**
 * @brief Saves images in the plain-text PPM (P3) format
 */
class PPMWriter : public virtual ImageWriter {
public:
  /// Constructs a PPM image writer
  PPMWriter();
  /// Destroys the PPM image writer
  ~PPMWriter();

  /**
   * @brief Writes an image to the given output file as a plain-text PPM
   *
   * @param image_data The image to save
   * @param output_file The path of the file to write to
   */
  void SaveImage(photon::Image &image_data, std::string output_file);
};
} // namespace photon::image_writer
