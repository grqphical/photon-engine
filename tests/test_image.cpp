#include "photon/image.hpp"
#include "photon/vector3.hpp"
#include <gtest/gtest.h>
#include <stdexcept>

TEST(ImageTests, TestConstructorAndDimensions) {
  photon::Image image(10, 20);

  EXPECT_EQ(image.Width(), 10u);
  EXPECT_EQ(image.Height(), 20u);
}

TEST(ImageTests, TestPixelDataInitialization) {
  photon::Image image(2, 2);

  for (auto it = image.CBegin(); it != image.CEnd(); ++it) {
    EXPECT_EQ(*it, 0u);
  }
}

TEST(ImageTests, TestSetPixelRGB) {
  photon::Image image(2, 2);

  image.SetPixel(1, 0, 255, 128, 64);

  auto it = image.Begin();
  uint32_t val = *(it + 1); // index (0 * 2 + 1) = 1

  uint32_t expected = (255u << 24) | (128u << 16) | (64u << 8);
  EXPECT_EQ(val, expected);
}

TEST(ImageTests, TestSetPixelVector3) {
  photon::Image image(2, 2);

  // Vector3 values clamped to [0.000, 0.999]
  photon::Vector3 color(0.5, 1.0, 0.0);
  image.SetPixel(0, 1, color);

  auto it = image.Begin();
  uint32_t val = *(it + 2); // index (1 * 2 + 0) = 2

  // 0.5 * 255 = 127
  // 1.0 clamped to 0.999 -> 0.999 * 255 = 254
  // 0.0 * 255 = 0
  uint32_t expected = (127u << 24) | (254u << 16) | (0u << 8);
  EXPECT_EQ(val, expected);
}

TEST(ImageTests, TestSetPixelOutOfBoundsThrows) {
  photon::Image image(5, 5);

  EXPECT_THROW(image.SetPixel(5, 0, 255, 255, 255), std::invalid_argument);
  EXPECT_THROW(image.SetPixel(0, 5, 255, 255, 255), std::invalid_argument);
  EXPECT_THROW(image.SetPixel(10, 10, photon::Vector3(1, 1, 1)), std::invalid_argument);
}

TEST(ImageTests, TestIterators) {
  photon::Image image(2, 2);

  image.SetPixel(0, 0, 10, 20, 30);
  image.SetPixel(1, 1, 40, 50, 60);

  size_t count = 0;
  for (auto it = image.Begin(); it != image.End(); ++it) {
    count++;
  }
  EXPECT_EQ(count, 4u);
}
