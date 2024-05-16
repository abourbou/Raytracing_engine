
#pragma once

#include <cstdint>
#include <cmath>
#include <iostream>
#include <Eigen/Dense>
#include "utils/engineTools.hpp"

/**
 * This class handle the camera
 * using https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays.html
 *
 * The camera position is (0, 0, 0) and the camera referential is (X, Y, -Z) from the world referential
 * with X the width of the screen, Y the height of the screen and -Z the direction of the camera
*/
class Camera
{
    public:
        Camera() = delete;
        Camera(double fov, uint32_t pixelWidth, uint32_t pixelHeight);
        Ray GetRay(uint32_t x, uint32_t y) const;

        // TODO Add later the movements of the camera

    private:
    // Width and height of the number of pixels in the image
    uint32_t PixelWidth, PixelHeight;

    Eigen::Vector3d CameraPos;
    Eigen::Matrix3d CameraRef;

    double Fov;
    double ImageAspectRatio;
} ;

