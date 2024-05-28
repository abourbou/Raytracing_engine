
#pragma once

#include "engineTools.hpp"
#include <Eigen/Dense>

class Object {
  public:
    virtual float intersect(const Ray& ray) = 0;
    virtual uint32_t getColor() = 0;
};