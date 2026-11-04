#include "photon/vector3.hpp"
#include <cmath>
#include <gtest/gtest.h>
#include <sstream>

TEST(Vector3Tests, TestVector3Negation) {
  photon::Vector3 expected(-1.0, -5.0, 15.6);
  photon::Vector3 vec3(1.0, 5.0, -15.6);

  ASSERT_EQ(-vec3, expected);
}

TEST(Vector3Tests, TestVector3AddEqual) {
  photon::Vector3 expected(1.0, 5.0, 15.0);

  photon::Vector3 vec1(1.0, 0.0, 5.0);
  photon::Vector3 vec2(0.0, 5.0, 10.0);

  vec1 += vec2;

  ASSERT_EQ(vec1, expected);
}

TEST(Vector3Tests, TestVector3SubtractEqual) {
  photon::Vector3 expected(-2.0, -5.0, 10.0);

  photon::Vector3 vec1(1.0, 0.0, 20.0);
  photon::Vector3 vec2(3.0, 5.0, 10.0);

  vec1 -= vec2;

  ASSERT_EQ(vec1, expected);
}

TEST(Vector3Tests, TestVector3MultiplyEqual) {
  photon::Vector3 expected(2.0, 0.0, 100.0);

  photon::Vector3 vec1(1.0, 0.0, 10.0);
  photon::Vector3 vec2(2.0, 5.0, 10.0);

  vec1 *= vec2;

  ASSERT_EQ(vec1, expected);
}

TEST(Vector3Tests, TestVector3DivideEqual) {
  photon::Vector3 expected(2.5, 7.0, 1.0);

  photon::Vector3 vec1(5.0, 49.0, 10.0);
  photon::Vector3 vec2(2.0, 7.0, 10.0);

  vec1 /= vec2;

  ASSERT_EQ(vec1, expected);
}

TEST(Vector3Tests, TestVector3LengthSquared) {
  double expected = 50.0;

  photon::Vector3 vec(3.0, 4.0, 5.0);

  ASSERT_EQ(vec.LengthSquared(), expected);
}

TEST(Vector3Tests, TestVector3Length) {
  double expected = std::sqrt(50.0);

  photon::Vector3 vec(3.0, 4.0, 5.0);

  ASSERT_EQ(vec.Length(), expected);
}

TEST(Vector3Tests, TestVector3Unit) {
  photon::Vector3 expected_vec(0.207514, 0.857726, 0.470366);
  double expected_magnitude_delta = 0.0001;

  photon::Vector3 vec(15, 62, 34);

  photon::Vector3 unit = vec.Unit();
  // this is to mitigate precision errors
  ASSERT_LT(1 - unit.Length(), expected_magnitude_delta);
}

TEST(Vector3Tests, TestVector3Equality) {
  photon::Vector3 vec1(1.0, 5.0, -6.0);
  photon::Vector3 vec2(1.0, 5.0, -6.0);
  photon::Vector3 vec3(2.0, 5.0, -6.0);
  photon::Vector3 vec4(2.0, -678.0, -6.0);

  ASSERT_EQ(vec1, vec2);
  ASSERT_EQ(vec2, vec1);
  ASSERT_NE(vec1, vec3);
  ASSERT_NE(vec2, vec3);
  ASSERT_NE(vec1, vec4);
  ASSERT_NE(vec2, vec4);
  ASSERT_NE(vec3, vec4);
}

TEST(Vector3Tests, TestVector3Addition) {
  photon::Vector3 expected(1.0, 5.0, -6.0);
  photon::Vector3 vec1(1.0, 3.0, -3.0);
  photon::Vector3 vec2(0.0, 2.0, -3.0);

  ASSERT_EQ(vec1 + vec2, expected);
}

TEST(Vector3Tests, TestVector3Subtraction) {
  photon::Vector3 expected(-4.0, 6.0, 0.0);
  photon::Vector3 vec1(1.0, 8.0, -3.0);
  photon::Vector3 vec2(5.0, 2.0, -3.0);

  ASSERT_EQ(vec1 - vec2, expected);
}

TEST(Vector3Tests, TestVector3Multiplication) {
  photon::Vector3 expected(1.0, 8.0, 6.0);
  photon::Vector3 vec1(1.0, 4.0, -3.0);
  photon::Vector3 vec2(1.0, 2.0, -2.0);

  ASSERT_EQ(vec1 * vec2, expected);
}

TEST(Vector3Tests, TestVector3Division) {
  photon::Vector3 expected(1.0, 2.0, 3.5);
  photon::Vector3 vec1(1.0, 4.0, -7.0);
  photon::Vector3 vec2(1.0, 2.0, -2.0);

  ASSERT_EQ(vec1 / vec2, expected);
}

TEST(Vector3Tests, TestVector3DotProduct) {
  double expected = -154.0;
  photon::Vector3 vec1(5.0, -8.0, 17.0);
  photon::Vector3 vec2(4.0, 9.0, -6.0);

  ASSERT_EQ(vec1 & vec2, expected);
}

TEST(Vector3Tests, TestVector3CrossProduct) {
  photon::Vector3 expected(327.0, -1047.0, -153.0);
  photon::Vector3 vec1(15.0, 6.0, -9.0);
  photon::Vector3 vec2(8.0, -7.0, 65.0);

  ASSERT_EQ(vec1 ^ vec2, expected);
}

TEST(Vector3Tests, TestVector3DefaultConstructor) {
  photon::Vector3 vec;

  ASSERT_EQ(vec.X(), 0.0);
  ASSERT_EQ(vec.Y(), 0.0);
  ASSERT_EQ(vec.Z(), 0.0);
}

TEST(Vector3Tests, TestVector3ComponentAccessors) {
  photon::Vector3 vec(1.5, -2.5, 3.5);

  ASSERT_EQ(vec.X(), 1.5);
  ASSERT_EQ(vec.Y(), -2.5);
  ASSERT_EQ(vec.Z(), 3.5);
}

TEST(Vector3Tests, TestVector3ScalarMultiplication) {
  photon::Vector3 vec(1.0, 2.0, 3.0);
  photon::Vector3 expected(2.0, 4.0, 6.0);

  ASSERT_EQ(vec * 2.0, expected);
  ASSERT_EQ(2.0 * vec, expected);
}

TEST(Vector3Tests, TestVector3ScalarDivision) {
  photon::Vector3 vec(2.0, 4.0, 6.0);
  photon::Vector3 expected(1.0, 2.0, 3.0);

  ASSERT_EQ(vec / 2.0, expected);
}

TEST(Vector3Tests, TestVector3RandomRange) {
  photon::Vector3 vec = photon::Vector3::Random();

  ASSERT_LE(0.0, vec.X());
  ASSERT_LT(vec.X(), 1.0);
  ASSERT_LE(0.0, vec.Y());
  ASSERT_LT(vec.Y(), 1.0);
  ASSERT_LE(0.0, vec.Z());
  ASSERT_LT(vec.Z(), 1.0);
}

TEST(Vector3Tests, TestVector3RandomRangeMinMax) {
  double min = -5.0;
  double max = 10.0;
  photon::Vector3 vec = photon::Vector3::Random(min, max);

  ASSERT_LE(min, vec.X());
  ASSERT_LT(vec.X(), max);
  ASSERT_LE(min, vec.Y());
  ASSERT_LT(vec.Y(), max);
  ASSERT_LE(min, vec.Z());
  ASSERT_LT(vec.Z(), max);
}

TEST(Vector3Tests, TestVector3RandomUnitLength) {
  photon::Vector3 vec = photon::Vector3::RandomUnit();

  ASSERT_NEAR(vec.Length(), 1.0, 1e-6);
}

TEST(Vector3Tests, TestVector3RandomOnHemisphere) {
  photon::Vector3 normal(0.0, 1.0, 0.0);
  photon::Vector3 vec = photon::Vector3::RandomOnHemisphere(normal);

  ASSERT_GE(vec & normal, 0.0);
}

TEST(Vector3Tests, TestVector3NearZero) {
  ASSERT_TRUE(photon::Vector3().NearZero());
  ASSERT_TRUE(photon::Vector3(1e-9, 0.0, 0.0).NearZero());
  ASSERT_FALSE(photon::Vector3(1.0, 0.0, 0.0).NearZero());
  ASSERT_FALSE(photon::Vector3(0.0, 1e-7, 0.0).NearZero());
}

TEST(Vector3Tests, TestVector3Reflect) {
  photon::Vector3 expected(1.0, 1.0, 0.0);
  photon::Vector3 vec(1.0, -1.0, 0.0);
  photon::Vector3 normal(0.0, 1.0, 0.0);

  ASSERT_EQ(vec.Reflect(normal), expected);

  photon::Vector3 expected2(-1.0, 0.0, 0.0);
  photon::Vector3 vec2(1.0, 0.0, 0.0);
  photon::Vector3 normal2(1.0, 0.0, 0.0);

  ASSERT_EQ(vec2.Reflect(normal2), expected2);
}

TEST(Vector3Tests, TestVector3StreamOutput) {
  std::ostringstream out;
  out << photon::Vector3(1.0, 2.0, 3.0);

  ASSERT_EQ(out.str(), "Vector3(1, 2, 3)");
}

TEST(Vector3Tests, TestVector3Point3Alias) {
  photon::Point3 p(4.0, 5.0, 6.0);

  ASSERT_EQ(p.X(), 4.0);
  ASSERT_EQ(p.Y(), 5.0);
  ASSERT_EQ(p.Z(), 6.0);
}
