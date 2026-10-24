#include "raytracer/vector3.hpp"
#include <cmath>
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

  vec1 /= vec2;

  ASSERT_EQ(vec1, expected);
}

TEST(Vector3Tests, TestVector3LengthSquared) {
  double expected = 50.0;

  raytracer::Vector3 vec(3.0, 4.0, 5.0);

  ASSERT_EQ(vec.LengthSquared(), expected);
}

TEST(Vector3Tests, TestVector3Length) {
  double expected = std::sqrt(50.0);

  raytracer::Vector3 vec(3.0, 4.0, 5.0);

  ASSERT_EQ(vec.Length(), expected);
}

TEST(Vector3Tests, TestVector3Unit) {
  raytracer::Vector3 expected_vec(0.207514, 0.857726, 0.470366);
  double expected_magnitude_delta = 0.0001;

  raytracer::Vector3 vec(15, 62, 34);

  raytracer::Vector3 unit = vec.Unit();
  // this is to mitigate precision errors
  ASSERT_LT(1 - unit.Length(), expected_magnitude_delta);
}

TEST(Vector3Tests, TestVector3Equality) {
  raytracer::Vector3 vec1(1.0, 5.0, -6.0);
  raytracer::Vector3 vec2(1.0, 5.0, -6.0);
  raytracer::Vector3 vec3(2.0, 5.0, -6.0);
  raytracer::Vector3 vec4(2.0, -678.0, -6.0);

  ASSERT_EQ(vec1, vec2);
  ASSERT_EQ(vec2, vec1);
  ASSERT_NE(vec1, vec3);
  ASSERT_NE(vec2, vec3);
  ASSERT_NE(vec1, vec4);
  ASSERT_NE(vec2, vec4);
  ASSERT_NE(vec3, vec4);
}

TEST(Vector3Tests, TestVector3Addition) {
  raytracer::Vector3 expected(1.0, 5.0, -6.0);
  raytracer::Vector3 vec1(1.0, 3.0, -3.0);
  raytracer::Vector3 vec2(0.0, 2.0, -3.0);

  ASSERT_EQ(vec1 + vec2, expected);
}

TEST(Vector3Tests, TestVector3Subtraction) {
  raytracer::Vector3 expected(-4.0, 6.0, 0.0);
  raytracer::Vector3 vec1(1.0, 8.0, -3.0);
  raytracer::Vector3 vec2(5.0, 2.0, -3.0);

  ASSERT_EQ(vec1 - vec2, expected);
}

TEST(Vector3Tests, TestVector3Multiplication) {
  raytracer::Vector3 expected(1.0, 8.0, 6.0);
  raytracer::Vector3 vec1(1.0, 4.0, -3.0);
  raytracer::Vector3 vec2(1.0, 2.0, -2.0);

  ASSERT_EQ(vec1 * vec2, expected);
}

TEST(Vector3Tests, TestVector3Division) {
  raytracer::Vector3 expected(1.0, 2.0, 3.5);
  raytracer::Vector3 vec1(1.0, 4.0, -7.0);
  raytracer::Vector3 vec2(1.0, 2.0, -2.0);

  ASSERT_EQ(vec1 / vec2, expected);
}

TEST(Vector3Tests, TestVector3DotProduct) {
  double expected = -154.0;
  raytracer::Vector3 vec1(5.0, -8.0, 17.0);
  raytracer::Vector3 vec2(4.0, 9.0, -6.0);

  ASSERT_EQ(vec1 & vec2, expected);
}

TEST(Vector3Tests, TestVector3CrossProduct) {
  raytracer::Vector3 expected(327.0, -1047.0, -153.0);
  raytracer::Vector3 vec1(15.0, 6.0, -9.0);
  raytracer::Vector3 vec2(8.0, -7.0, 65.0);

  ASSERT_EQ(vec1 ^ vec2, expected);
}
