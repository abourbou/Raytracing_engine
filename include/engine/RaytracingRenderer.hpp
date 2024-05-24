
#pragma once

#include <Eigen/Dense>
#include <limits>
#include <memory>
#include <vector>

#include "Camera.hpp"
#include "Object.hpp"
#include "SceneOptions.hpp"
#include "Sphere.hpp"

class Lights {};

class RayTracingRenderer {
  public:
    RayTracingRenderer() = delete;
    RayTracingRenderer(const SceneOptions& options);
    void render();

  private:
    std::vector<std::unique_ptr<Object>> SceneObjects;
    std::vector<Lights> SceneLights;
    std::unique_ptr<Camera> Cam;
    std::unique_ptr<SceneOptions> Options;
};