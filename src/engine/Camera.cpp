
#include "engine/Camera.hpp"

Camera::Camera(double fov, uint32_t pixelWidth, uint32_t pixelHeight)
    : PixelWidth(pixelWidth), PixelHeight(pixelHeight), Fov(fov) {
    this->ImageAspectRatio = (double)pixelWidth / (double)pixelHeight;
}

Ray Camera::GetRay(uint32_t x, uint32_t y) const {
    assert(x < this->PixelWidth && y < this->PixelHeight);

    double px = (((x + 0.5) / (double)this->PixelWidth) * 2 - 1.) * this->ImageAspectRatio *
                tan(deg2rad(this->Fov / 2.));
    double py = (1. - ((y + 0.5) / (double)this->PixelHeight) * 2) * tan(deg2rad(this->Fov / 2.));

    Ray primaryRay = {Eigen::Vector3d::Zero(), Eigen::Vector3d::Zero()};
    primaryRay.Direction = (Eigen::Vector3d(px, py, -1.) - primaryRay.Origin).normalized();

    return primaryRay;
}