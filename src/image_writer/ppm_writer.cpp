#include "photon/image_writer/ppm_writer.hpp"
#include "photon/image.hpp"

#include <fstream>
#include <iostream>

photon::image_writer::PPMWriter::PPMWriter() {}

photon::image_writer::PPMWriter::~PPMWriter() {}

void photon::image_writer::PPMWriter::SaveImage(photon::Image &image_data,
                                                std::string output_file) {
  std::ofstream output(output_file);

  output << "P3\n"
         << image_data.Width() << ' ' << image_data.Height() << "\n255\n";

  for (auto it = image_data.Begin(); it != image_data.End(); ++it) {
    const uint8_t red = static_cast<uint8_t>((*it >> 24) & 0xFF);
    const uint8_t green = static_cast<uint8_t>((*it >> 16) & 0xFF);
    const uint8_t blue = static_cast<uint8_t>((*it >> 8) & 0xFF);

    output << std::to_string(red) << ' ' << std::to_string(green) << ' '
           << std::to_string(blue) << '\n';
  }

  output.close();
}
