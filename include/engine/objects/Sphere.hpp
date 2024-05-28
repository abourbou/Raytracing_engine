
#pragma once

#include "Object.hpp"

class Sphere : public Object {
  public:
    Sphere() = delete;
    Sphere(Eigen::Vector3f center, float radius, uint32_t color)
        : Center(center), Radius(radius), Color(color) {}
    float intersect(const Ray& ray);
    uint32_t getColor() { return this->Color; };

  private:
    Eigen::Vector3f Center;
    float Radius;
    uint32_t Color;
};