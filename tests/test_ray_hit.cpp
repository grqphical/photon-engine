#include "photon/ray_hit.hpp"
#include "photon/ray.hpp"
#include "photon/vector3.hpp"
#include <gtest/gtest.h>

TEST(RayHitTests, TestSetFaceNormalFrontFace) {
  photon::Ray ray(photon::Vector3(0.0, 0.0, 0.0),
                  photon::Vector3(0.0, 0.0, -1.0));
  photon::Vector3 outwardNormal(0.0, 0.0, 1.0);

  photon::RayHit hit;
  hit.SetFaceNormal(ray, outwardNormal);

  EXPECT_TRUE(hit.front_face);
  EXPECT_EQ(hit.normal, outwardNormal);
}

TEST(RayHitTests, TestSetFaceNormalBackFace) {
  photon::Ray ray(photon::Vector3(0.0, 0.0, 0.0),
                  photon::Vector3(0.0, 0.0, 1.0));
  photon::Vector3 outwardNormal(0.0, 0.0, 1.0);

  photon::RayHit hit;
  hit.SetFaceNormal(ray, outwardNormal);

  EXPECT_FALSE(hit.front_face);
  EXPECT_EQ(hit.normal, -outwardNormal);
}
