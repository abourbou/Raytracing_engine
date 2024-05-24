
#include "engine/Camera.hpp"

Camera::Camera(float fov, uint32_t pixelWidth, uint32_t pixelHeight) {
    this->SetPixelParameters(pixelWidth, pixelHeight);
    this->SetFov(fov);
}

void Camera::SetPixelParameters(uint32_t pixelWidth, uint32_t pixelHeight) {
    this->PixelWidth = pixelWidth;
    this->PixelHeight = pixelHeight;
    this->ImageAspectRatio = (float)pixelWidth / (float)pixelHeight;
}

void Camera::SetFov(float fov) {
    assert(fov < 180.);
    this->Fov = fov;
    this->TanHalfFov = tan(deg2rad(this->Fov / 2.));
}

Ray Camera::GetRay(uint32_t x, uint32_t y) const {
    assert(x < this->PixelWidth && y < this->PixelHeight);

    float px = (((x + 0.5) / (float)this->PixelWidth) * 2 - 1.) *
               this->ImageAspectRatio * this->TanHalfFov;
    float py =
        (1. - ((y + 0.5) / (float)this->PixelHeight) * 2) * this->TanHalfFov;

    Ray primaryRay = {Eigen::Vector3f::Zero(), Eigen::Vector3f::Zero()};
    primaryRay.Direction =
        (Eigen::Vector3f(px, py, -1.) - primaryRay.Origin).normalized();

    return primaryRay;
}