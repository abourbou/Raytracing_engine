
#pragma once

#include <Eigen/Dense>
#include <math.h>

struct Ray {

    Ray() = delete;
    Ray(Eigen::Vector3d origin, Eigen::Vector3d direction)
        : Origin(origin), Direction(direction.normalized()) {}

    Eigen::Vector3d Origin;
    Eigen::Vector3d Direction;
};

inline float deg2rad(const float& deg) { return deg * M_PI / 180; }