#pragma once

#include "photon/image.hpp"
#include "photon/image_writer/image_writer.hpp"

namespace photon::image_writer {
class PPMWriter : public virtual ImageWriter {
public:
  PPMWriter();
  ~PPMWriter();

  void SaveImage(photon::Image &image_data, std::string output_file);
};
} // namespace photon::image_writer
