#pragma once
#include <ostream>

namespace photon {
/**
 * @brief A three-dimensional vector with double precision components
 */
class Vector3 {
public:
  /// Default constructs a zero vector
  Vector3();

  /**
   * @brief Constructs a vector from its components
   *
   * @param x The x component
   * @param y The y component
   * @param z The z component
   */
  Vector3(double x, double y, double z);

  /// Generates a Vector3 of random values between 0.0 and 1.0
  static Vector3 Random();

  /**
   * @brief Generates a random Vector3
   *
   * @param min The minimum value
   * @param max The maximum value
   */
  static Vector3 Random(double min, double max);

  /// Returns the x component
  double X() const;
  /// Returns the y component
  double Y() const;
  /// Returns the z component
  double Z() const;

  /// Returns the negation of this vector
  Vector3 operator-() const;
  /// Adds another vector component-wise and returns this vector
  Vector3 &operator+=(const Vector3 &v);
  /// Subtracts another vector component-wise and returns this vector
  Vector3 &operator-=(const Vector3 &v);
  /// Multiplies component-wise with another vector and returns this vector
  Vector3 &operator*=(const Vector3 &v);
  /// Divides component-wise by another vector and returns this vector
  Vector3 &operator/=(const Vector3 &v);

  /// Returns the Euclidean length of this vector
  double Length() const;
  /// Returns the squared Euclidean length of this vector
  double LengthSquared() const;

  /// Returns a unit-length copy of this vector
  Vector3 Unit() const;

  Vector3 RandomUnit() const;

private:
  double x, y, z;
};

/**
 * @brief Streams a vector in the form Vector3(x, y, z)
 *
 * @param out The output stream
 * @param a The vector to print
 *
 * @return The output stream
 */
std::ostream &operator<<(std::ostream &out, const Vector3 &a);

/// Returns true if both vectors have exactly equal components
bool operator==(const Vector3 &a, const Vector3 &b);

/// Returns the component-wise sum of two vectors
Vector3 operator+(const Vector3 &a, const Vector3 &b);
/// Returns the component-wise difference of two vectors
Vector3 operator-(const Vector3 &a, const Vector3 &b);
/// Returns the component-wise quotient of two vectors
Vector3 operator/(const Vector3 &a, const Vector3 &b);
/// Returns the vector divided by a scalar
Vector3 operator/(const Vector3 &a, double b);
/// Returns the component-wise product of two vectors
Vector3 operator*(const Vector3 &a, const Vector3 &b);
/// Returns a scalar multiplied by a vector
Vector3 operator*(double a, const Vector3 &b);
/// Returns a vector multiplied by a scalar
Vector3 operator*(const Vector3 &a, double b);

/**
 * @brief Returns the dot product of two vectors
 *
 * Uses the "&" operator for the dot product.
 */
double operator&(const Vector3 &a, const Vector3 &b);

/**
 * @brief Returns the cross product of two vectors
 *
 * Uses the "^" operator for the cross product.
 */
Vector3 operator^(const Vector3 &a, const Vector3 &b);

/// Alias indicating a Vector3 used as a position in space
using Point3 = Vector3;

} // namespace photon
