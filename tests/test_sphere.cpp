#include "photon/interval.hpp"
#include "photon/materials/lambertian.hpp"
#include "photon/objects/sphere.hpp"
#include "photon/ray.hpp"
#include "photon/ray_hit.hpp"
#include "photon/vector3.hpp"
#include <gtest/gtest.h>
#include <memory>

TEST(SphereTests, TestRayHitDirectHit) {
  auto mat = std::make_shared<photon::materials::Lambertian>(
      photon::Vector3(0.8, 0.8, 0.8));
  photon::objects::Sphere sphere(photon::Vector3(0.0, 0.0, -5.0), 1.0, mat);

  photon::Ray ray(photon::Vector3(0.0, 0.0, 0.0),
                  photon::Vector3(0.0, 0.0, -1.0));
  photon::Interval rayRange(0.001, 100.0);
  photon::RayHit hit;

  ASSERT_TRUE(sphere.RayHit(ray, rayRange, hit));
  EXPECT_DOUBLE_EQ(hit.t, 4.0);
  EXPECT_EQ(hit.point, photon::Vector3(0.0, 0.0, -4.0));
  EXPECT_EQ(hit.normal, photon::Vector3(0.0, 0.0, 1.0));
  EXPECT_TRUE(hit.front_face);
  EXPECT_EQ(hit.material, mat);
}

TEST(SphereTests, TestRayHitMiss) {
  auto mat = std::make_shared<photon::materials::Lambertian>(
      photon::Vector3(0.8, 0.8, 0.8));
  photon::objects::Sphere sphere(photon::Vector3(0.0, 0.0, -5.0), 1.0, mat);

  photon::Ray ray(photon::Vector3(0.0, 5.0, 0.0),
                  photon::Vector3(0.0, 0.0, -1.0));
  photon::Interval rayRange(0.001, 100.0);
  photon::RayHit hit;

  EXPECT_FALSE(sphere.RayHit(ray, rayRange, hit));
}

TEST(SphereTests, TestRayHitInsideSphere) {
  auto mat = std::make_shared<photon::materials::Lambertian>(
      photon::Vector3(0.8, 0.8, 0.8));
  photon::objects::Sphere sphere(photon::Vector3(0.0, 0.0, 0.0), 2.0, mat);

  photon::Ray ray(photon::Vector3(0.0, 0.0, 0.0),
                  photon::Vector3(0.0, 0.0, 1.0));
  photon::Interval rayRange(0.001, 100.0);
  photon::RayHit hit;

  ASSERT_TRUE(sphere.RayHit(ray, rayRange, hit));
  EXPECT_DOUBLE_EQ(hit.t, 2.0);
  EXPECT_EQ(hit.point, photon::Vector3(0.0, 0.0, 2.0));
  EXPECT_EQ(hit.normal, photon::Vector3(0.0, 0.0, -1.0));
  EXPECT_FALSE(hit.front_face);
}

TEST(SphereTests, TestRayHitRangeClamping) {
  auto mat = std::make_shared<photon::materials::Lambertian>(
      photon::Vector3(0.8, 0.8, 0.8));
  photon::objects::Sphere sphere(photon::Vector3(0.0, 0.0, -5.0), 1.0, mat);

  photon::Ray ray(photon::Vector3(0.0, 0.0, 0.0),
                  photon::Vector3(0.0, 0.0, -1.0));
  photon::RayHit hit;

  // Range is before the hit point (hit is at t=4.0)
  EXPECT_FALSE(sphere.RayHit(ray, photon::Interval(0.0, 3.0), hit));
}
