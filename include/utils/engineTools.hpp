
#pragma once

#include <Eigen/Dense>
#include <math.h>

struct Ray {

    Ray() = delete;
    Ray(Eigen::Vector3f origin, Eigen::Vector3f direction)
        : Origin(origin), Direction(direction.normalized()) {}

    Eigen::Vector3f Origin;
    Eigen::Vector3f Direction;
};

inline float deg2rad(const float& deg) { return deg * M_PI / 180; }

bool solveQuadratic(const float& a, const float& b, const float& c, float& x0,
                    float& x1);
