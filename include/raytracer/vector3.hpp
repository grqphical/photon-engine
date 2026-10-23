#pragma once
#include <ostream>

namespace raytracer {
class Vector3 {
public:
  Vector3();
  Vector3(double x, double y, double z);

  double X() const;
  double Y() const;
  double Z() const;

  Vector3 operator-() const;
  Vector3 operator+=(const Vector3 &v);
  Vector3 operator-=(const Vector3 &v);
  Vector3 operator*=(const Vector3 &v);
  Vector3 operator/=(const Vector3 &v);

  double Length() const;
  double LengthSquared() const;

  // applies the dot product of this Vector and a to this Vector
  void DotProduct(Vector3 &a);
  void CrossProduct(Vector3 &a);
  Vector3 Unit() const;

private:
  double x, y, z;
};

std::ostream &operator<<(std::ostream &out, const Vector3 &a);
bool operator==(const Vector3 &a, const Vector3 &b);

Vector3 operator+(const Vector3 &a, const Vector3 &b);
Vector3 operator-(const Vector3 &a, const Vector3 &b);
Vector3 operator/(const Vector3 &a, const Vector3 &b);
Vector3 operator*(const Vector3 &a, const Vector3 &b);
Vector3 operator*(double a, const Vector3 &b);
Vector3 operator*(const Vector3 &a, double b);

using Point3 = Vector3;
} // namespace raytracer
