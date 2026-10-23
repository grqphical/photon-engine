#include "raytracer/vector3.hpp"

namespace raytracer {

Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {}

Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

bool operator==(const raytracer::Vector3 &a, const raytracer::Vector3 &b) {
  return (a.X() == b.X()) && (a.Y() == b.Y()) && (a.Z() == b.Z());
}

std::ostream &operator<<(std::ostream &out, const raytracer::Vector3 &a) {
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
} // namespace raytracer
