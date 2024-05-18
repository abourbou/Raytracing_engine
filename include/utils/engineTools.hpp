
#pragma once

#include <math.h>

struct Ray {
    Eigen::Vector3d Origin;
    Eigen::Vector3d Direction;
};

inline float deg2rad(const float& deg) { return deg * M_PI / 180; }