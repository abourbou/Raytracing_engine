
#pragma once

#include "engineTools.hpp"

class Object {
  public:
    virtual double intersect(const Ray& ray) = 0;
};