
#include "RaytracingRenderer.hpp"

void RayTracingRenderer::render() {
    for (int x = 0; x < this->Options->GetWidthScreen(); ++x) {
        for (int y = 0; y < this->Options->GetHeightScreen(); ++y) {
            auto ray = this->Cam->GetRay(x, y);
        }
    }
}