#include "raytracer/vector3.hpp"
#include <gtest/gtest.h>

TEST(Vector3Tests, TestVector3Negation) {
  raytracer::Vector3 expected(-1.0, -5.0, 15.6);
  raytracer::Vector3 vec3(1.0, 5.0, -15.6);

  ASSERT_EQ(-vec3, expected);
}

TEST(Vector3Tests, TestVector3AddEqual) {
  raytracer::Vector3 expected(1.0, 5.0, 15.0);

  raytracer::Vector3 vec1(1.0, 0.0, 5.0);
  raytracer::Vector3 vec2(0.0, 5.0, 10.0);

  vec1 += vec2;

  ASSERT_EQ(vec1, expected);
}

TEST(Vector3Tests, TestVector3SubtractEqual) {
  raytracer::Vector3 expected(-2.0, -5.0, 10.0);

  raytracer::Vector3 vec1(1.0, 0.0, 20.0);
  raytracer::Vector3 vec2(3.0, 5.0, 10.0);

  vec1 -= vec2;

  ASSERT_EQ(vec1, expected);
}

TEST(Vector3Tests, TestVector3MultiplyEqual) {
  raytracer::Vector3 expected(2.0, 0.0, 100.0);

  raytracer::Vector3 vec1(1.0, 0.0, 10.0);
  raytracer::Vector3 vec2(2.0, 5.0, 10.0);

  vec1 *= vec2;

  ASSERT_EQ(vec1, expected);
}

TEST(Vector3Tests, TestVector3DivideEqual) {
  raytracer::Vector3 expected(2.5, 7.0, 1.0);

  raytracer::Vector3 vec1(5.0, 49.0, 10.0);
  raytracer::Vector3 vec2(2.0, 7.0, 10.0);

  vec1 *= vec2;

  ASSERT_EQ(vec1, expected);
}
