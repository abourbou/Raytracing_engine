
#include "RaytracingRenderer.hpp"

RayTracingRenderer::RayTracingRenderer(const SceneOptions& options)
    : Options(std::make_unique<SceneOptions>(options)) {
    this->Cam = std::make_unique<Camera>(
        options.GetFov(), options.GetWidthScreen(), options.GetHeightScreen());

    this->SceneObjects.emplace_back(
        std::make_unique<Sphere>(Eigen::Vector3f(0., 0., -2.), 1.));
};

void RayTracingRenderer::render(ImageHandler& imageInstance) {
    for (int x = 0; x < this->Options->GetWidthScreen(); ++x) {
        for (int y = 0; y < this->Options->GetHeightScreen(); ++y) {
            auto ray = this->Cam->GetRay(x, y);
            float maxDist = std::numeric_limits<float>::infinity();
            auto closestObj = this->SceneObjects.end();
            float buffDist;
            for (auto obj = this->SceneObjects.begin();
                 obj < this->SceneObjects.end(); ++obj) {
                buffDist = -1.;
                buffDist = (*obj)->intersect(ray);
                if (buffDist > 0. && buffDist < maxDist) {
                    maxDist = buffDist;
                    closestObj = obj;
                }
            }
            if (closestObj != this->SceneObjects.end()) {
                // Set the color to red
                imageInstance.SetPixel(x, y, 255, 0, 0);
            }
        }
    }
}