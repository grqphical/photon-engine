#include "photon/interval.hpp"
#include <gtest/gtest.h>

TEST(IntervalTests, TestDefaultConstructor) {
  photon::Interval interval;

  EXPECT_GT(interval.Min(), 0.0);
  EXPECT_LT(interval.Max(), 0.0);
  EXPECT_TRUE(std::isinf(interval.Min()));
  EXPECT_TRUE(std::isinf(interval.Max()));
}

TEST(IntervalTests, TestCustomConstructorAndAccessors) {
  photon::Interval interval(1.5, 5.5);

  EXPECT_EQ(interval.Min(), 1.5);
  EXPECT_EQ(interval.Max(), 5.5);
}

TEST(IntervalTests, TestSize) {
  photon::Interval interval(2.0, 7.5);

  EXPECT_DOUBLE_EQ(interval.Size(), 5.5);
}

TEST(IntervalTests, TestContains) {
  photon::Interval interval(1.0, 5.0);

  EXPECT_TRUE(interval.Contains(1.0));
  EXPECT_TRUE(interval.Contains(3.0));
  EXPECT_TRUE(interval.Contains(5.0));

  EXPECT_FALSE(interval.Contains(0.999));
  EXPECT_FALSE(interval.Contains(5.001));
}

TEST(IntervalTests, TestSurrounds) {
  photon::Interval interval(1.0, 5.0);

  EXPECT_FALSE(interval.Surrounds(1.0));
  EXPECT_TRUE(interval.Surrounds(1.0001));
  EXPECT_TRUE(interval.Surrounds(3.0));
  EXPECT_TRUE(interval.Surrounds(4.9999));
  EXPECT_FALSE(interval.Surrounds(5.0));

  EXPECT_FALSE(interval.Surrounds(0.5));
  EXPECT_FALSE(interval.Surrounds(5.5));
}

TEST(IntervalTests, TestClamp) {
  photon::Interval interval(2.0, 8.0);

  EXPECT_DOUBLE_EQ(interval.Clamp(0.0), 2.0);
  EXPECT_DOUBLE_EQ(interval.Clamp(2.0), 2.0);
  EXPECT_DOUBLE_EQ(interval.Clamp(5.0), 5.0);
  EXPECT_DOUBLE_EQ(interval.Clamp(8.0), 8.0);
  EXPECT_DOUBLE_EQ(interval.Clamp(10.0), 8.0);
}

TEST(IntervalTests, TestStaticConstants) {
  EXPECT_TRUE(photon::Interval::empty.Min() > photon::Interval::empty.Max());
  EXPECT_TRUE(photon::Interval::universe.Min() < photon::Interval::universe.Max());
}
