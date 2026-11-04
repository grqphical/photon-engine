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

TEST(RayTests, TestRayDefaultConstructor) {
  photon::Ray ray;

  ASSERT_EQ(ray.Origin(), photon::Vector3());
  ASSERT_EQ(ray.Direction(), photon::Vector3());
}

TEST(RayTests, TestRayOriginAccessor) {
  photon::Vector3 origin(3.0, 4.0, 5.0);
  photon::Vector3 direction(1.0, 1.0, 3.0);
  photon::Ray ray(origin, direction);

  ASSERT_EQ(ray.Origin(), origin);
}

TEST(RayTests, TestRayDirectionAccessor) {
  photon::Vector3 origin(3.0, 4.0, 5.0);
  photon::Vector3 direction(1.0, 1.0, 3.0);
  photon::Ray ray(origin, direction);

  ASSERT_EQ(ray.Direction(), direction);
}

TEST(RayTests, TestRayAtZero) {
  photon::Vector3 origin(3.0, 4.0, 5.0);
  photon::Vector3 direction(1.0, 1.0, 3.0);
  photon::Ray ray(origin, direction);

  ASSERT_EQ(ray.At(0.0), origin);
}

TEST(RayTests, TestRayAtNegativeT) {
  photon::Vector3 origin(3.0, 4.0, 5.0);
  photon::Vector3 direction(1.0, 1.0, 3.0);
  photon::Ray ray(origin, direction);

  photon::Vector3 expected(1.0, 2.0, -1.0);
  ASSERT_EQ(ray.At(-2.0), expected);
}
