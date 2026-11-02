#include "photon/vector3.hpp"
#include "photon/photon.hpp"
#include <cmath>

namespace photon {

Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {}

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3 Vector3::Random() {
  return Vector3(RandomDouble(), RandomDouble(), RandomDouble());
}

Vector3 Vector3::Random(double min, double max) {
  return Vector3(RandomDouble(min, max), RandomDouble(min, max), RandomDouble(min, max));
}

bool operator==(const photon::Vector3 &a, const photon::Vector3 &b) {
  return (a.X() == b.X()) && (a.Y() == b.Y()) && (a.Z() == b.Z());
}

std::ostream &operator<<(std::ostream &out, const photon::Vector3 &a) {
  return out << "Vector3(" << a.X() << ", " << a.Y() << ", " << a.Z() << ")";
}

double Vector3::X() const { return this->x; }
double Vector3::Y() const { return this->y; }
double Vector3::Z() const { return this->z; }

Vector3 Vector3::operator-() const {
  Vector3 vec(-this->x, -this->y, -this->z);
  return vec;
}
Vector3 &Vector3::operator+=(const Vector3 &v) {
  this->x += v.X();
  this->y += v.Y();
  this->z += v.Z();
  return *this;
}
Vector3 &Vector3::operator-=(const Vector3 &v) {
  this->x -= v.X();
  this->y -= v.Y();
  this->z -= v.Z();
  return *this;
}
Vector3 &Vector3::operator*=(const Vector3 &v) {
  this->x *= v.X();
  this->y *= v.Y();
  this->z *= v.Z();
  return *this;
}
Vector3 &Vector3::operator/=(const Vector3 &v) {
  this->x /= v.X();
  this->y /= v.Y();
  this->z /= v.Z();
  return *this;
}

Vector3 operator+(const Vector3 &a, const Vector3 &b) {
  return Vector3(a.X() + b.X(), a.Y() + b.Y(), a.Z() + b.Z());
}

Vector3 operator-(const Vector3 &a, const Vector3 &b) {
  return Vector3(a.X() - b.X(), a.Y() - b.Y(), a.Z() - b.Z());
}

Vector3 operator*(const Vector3 &a, const Vector3 &b) {
  return Vector3(a.X() * b.X(), a.Y() * b.Y(), a.Z() * b.Z());
}

Vector3 operator*(const Vector3 &a, double b) {
  return Vector3(a.X() * b, a.Y() * b, a.Z() * b);
}

Vector3 operator*(double a, const Vector3 &b) { return b * a; }

Vector3 operator/(const Vector3 &a, double b) { return (1 / b) * a; }

Vector3 operator/(const Vector3 &a, const Vector3 &b) {
  return Vector3(a.X() / b.X(), a.Y() / b.Y(), a.Z() / b.Z());
}

double Vector3::LengthSquared() const { return x * x + y * y + z * z; }

double Vector3::Length() const { return std::sqrt(this->LengthSquared()); }

Vector3 Vector3::Unit() const { return *this / this->Length(); }

double operator&(const Vector3 &a, const Vector3 &b) {
  // dot product
  return (a.X() * b.X()) + (a.Y() * b.Y()) + (a.Z() * b.Z());
}

Vector3 operator^(const Vector3 &a, const Vector3 &b) {
  // cross product
  return Vector3(a.Y() * b.Z() - a.Z() * b.Y(), a.Z() * b.X() - a.X() * b.Z(),
                 a.X() * b.Y() - a.Y() * b.X());
}
} // namespace photon
