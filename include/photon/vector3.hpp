#pragma once
#include <ostream>

namespace photon {
class Vector3 {
public:
  Vector3();
  Vector3(double x, double y, double z);

  double X() const;
  double Y() const;
  double Z() const;

  Vector3 operator-() const;
  Vector3 &operator+=(const Vector3 &v);
  Vector3 &operator-=(const Vector3 &v);
  Vector3 &operator*=(const Vector3 &v);
  Vector3 &operator/=(const Vector3 &v);

  double Length() const;
  double LengthSquared() const;

  Vector3 Unit() const;

private:
  double x, y, z;
};

std::ostream &operator<<(std::ostream &out, const Vector3 &a);
bool operator==(const Vector3 &a, const Vector3 &b);

Vector3 operator+(const Vector3 &a, const Vector3 &b);
Vector3 operator-(const Vector3 &a, const Vector3 &b);
Vector3 operator/(const Vector3 &a, const Vector3 &b);
Vector3 operator/(const Vector3 &a, double b);
Vector3 operator*(const Vector3 &a, const Vector3 &b);
Vector3 operator*(double a, const Vector3 &b);
Vector3 operator*(const Vector3 &a, double b);

// use the "&" operator for dot product
double operator&(const Vector3 &a, const Vector3 &b);

// use the "^" operator for cross product
Vector3 operator^(const Vector3 &a, const Vector3 &b);

using Point3 = Vector3;

} // namespace photon
