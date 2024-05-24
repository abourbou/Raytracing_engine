
#pragma once

#include "Object.hpp"

class Sphere : public Object {
  public:
    Sphere() = delete;
    Sphere(Eigen::Vector3f center, float radius)
        : Center(center), Radius(radius) {}
    float intersect(const Ray& ray);

  private:
    Eigen::Vector3f Center;
    float Radius;
};