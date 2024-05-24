
#pragma once

#include "utils/engineTools.hpp"
#include <Eigen/Dense>
#include <cmath>
#include <cstdint>
#include <iostream>

/**
 * This class handle the camera
 * using
 * https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays.html
 *
 * The camera position is (0, 0, 0) and the camera referential is (X, Y, -Z)
 * from the world referential with X the width of the screen, Y the height of
 * the screen and -Z the direction of the camera
 */
// TODO Add the movements of the camera
class Camera {
  public:
    Camera() = delete;
    Camera(float fov, uint32_t pixelWidth, uint32_t pixelHeight);
    Ray GetRay(uint32_t x, uint32_t y) const;

    void SetPixelParameters(uint32_t pixelWidth, uint32_t pixelHeight);
    void SetFov(float fov);

  private:
    // Pixel parameters
    uint32_t PixelWidth, PixelHeight;
    float ImageAspectRatio;

    Eigen::Vector3f CameraPos;
    Eigen::Matrix3f CameraRef;

    float Fov;
    float TanHalfFov;
};
