
#pragma once

#include <memory>
#include <vector>
#include <Eigen/Dense>

#include "Camera.hpp"
#include "SceneOptions.hpp"

class Objects{};
class Lights{};

class RayTracingRenderer
{
    public:
        RayTracingRenderer() = delete;
        RayTracingRenderer(SceneOptions options)
        {
            this->Cam = std::make_unique<Camera>(options.GetFov(),
                                            options.GetWidthScreen(),
                                            options.GetHeightScreen()
                                        );
        };
        void render();

    private:
        std::vector<Objects> SceneObjects;
        std::vector<Lights> SceneLights;
        std::unique_ptr<Camera> Cam;
};