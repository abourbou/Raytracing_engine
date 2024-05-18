
#pragma once

#include "Object.hpp"

class Sphere : public Object {
  public:
    Sphere() = delete;
    Sphere(Eigen::Vector3d pos, double radius) : Position(pos), Radius(radius) {}
    double intersect(const Ray& ray);

  private:
    Eigen::Vector3d Position;
    double Radius;
};