#include "raytracer/objects/sphere.hpp"

namespace raytracer::objects {

Sphere::Sphere(Vector3 center, double radius, Vector3 colour)
    : center(center), colour(colour), radius(radius) {}

} // namespace raytracer::objects
