#include "raytracer/ray.hpp"
#include "raytracer/vector3.hpp"
#include <gmock/gmock.h>

TEST(RayTests, TestRayAt) {
  raytracer::Vector3 expected(13.0, 14.0, 35.0);

  raytracer::Ray ray(raytracer::Vector3(3.0, 4.0, 5.0),
                     raytracer::Vector3(1.0, 1.0, 3.0));
  raytracer::Vector3 result = ray.At(10.0);

  ASSERT_EQ(result, expected);
}
