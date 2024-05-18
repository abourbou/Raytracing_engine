
#include "SceneOptions.hpp"

void SceneOptions::SetFov(double fov) {
    if (fov < 30. || fov > 150.)
        throw InvalidInput("fov");
    this->Fov = fov;
}

void SceneOptions::SetWidthScreen(uint32_t WidthScreen) {
    if (WidthScreen > 2048 || WidthScreen < 1)
        throw InvalidInput("width screen size");
}

void SceneOptions::SetHeightScreen(uint32_t HeightScreen) {
    if (HeightScreen > 2048 || HeightScreen < 1)
        throw InvalidInput("height screen size");
}