
#include "engine/Camera.hpp"

Camera::Camera(double fov, uint32_t pixelWidth, uint32_t pixelHeight) {
    this->SetPixelParameters(pixelWidth, pixelHeight);
    this->SetFov(fov);
}

void Camera::SetPixelParameters(uint32_t pixelWidth, uint32_t pixelHeight) {
    this->PixelWidth = pixelWidth;
    this->PixelHeight = pixelHeight;
    this->ImageAspectRatio = (double)pixelWidth / (double)pixelHeight;
}

void Camera::SetFov(double fov) {
    assert(fov < 180.);
    this->Fov = fov;
    this->TanHalfFov = tan(deg2rad(this->Fov / 2.));
}

Ray Camera::GetRay(uint32_t x, uint32_t y) const {
    assert(x < this->PixelWidth && y < this->PixelHeight);

    double px = (((x + 0.5) / (double)this->PixelWidth) * 2 - 1.) * this->ImageAspectRatio *
                this->TanHalfFov;
    double py = (1. - ((y + 0.5) / (double)this->PixelHeight) * 2) * this->TanHalfFov;

    Ray primaryRay = {Eigen::Vector3d::Zero(), Eigen::Vector3d::Zero()};
    primaryRay.Direction = (Eigen::Vector3d(px, py, -1.) - primaryRay.Origin).normalized();

    return primaryRay;
}