
#pragma once

#include <Eigen/Dense>
#include <math.h>

#define RGB_TO_ARGB888(red, green, blue)                                       \
    0xFF000000 | (red << 16) | (green << 8) | blue

struct Ray {

    Ray() = delete;
    Ray(Eigen::Vector3f origin, Eigen::Vector3f direction)
        : Origin(origin), Direction(direction.normalized()) {}

    Eigen::Vector3f Origin;
    Eigen::Vector3f Direction;
};

inline float deg2rad(const float& deg) { return deg * M_PI / 180; }
