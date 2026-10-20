#pragma once

#include "raytracer/image.hpp"
#include "raytracer/image_writer/image_writer.hpp"

namespace raytracer::image_writer {
class PPMWriter : public virtual ImageWriter {
public:
  PPMWriter();
  ~PPMWriter();

  void SaveImage(raytracer::Image &image_data, std::string output_file);
};
} // namespace raytracer::image_writer
