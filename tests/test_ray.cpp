#include "photon/ray.hpp"
#include "photon/vector3.hpp"
#include <gmock/gmock.h>

TEST(RayTests, TestRayAt) {
  photon::Vector3 expected(13.0, 14.0, 35.0);

  photon::Ray ray(photon::Vector3(3.0, 4.0, 5.0),
                  photon::Vector3(1.0, 1.0, 3.0));
  photon::Vector3 result = ray.At(10.0);

  ASSERT_EQ(result, expected);
}
