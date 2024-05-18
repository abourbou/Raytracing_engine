
#include "AppRenderer.hpp"

AppRenderer::AppRenderer() { this->IsRunning = true; }

bool AppRenderer::Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;

    // Initialize the window
    this->Window =
        SDL_CreateWindow("Raytracing Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                         WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!this->Window)
        return false;

    // Initialise the SDL renderer
    this->Renderer = SDL_CreateRenderer(this->Window, -1, 0);

    // Initialize the image
    this->ImageInstance = ImageHandler();
    this->ImageInstance.Initialize(WINDOW_WIDTH, WINDOW_HEIGHT, this->Renderer);

    // Init engine
    SceneOptions opt;
    opt.SetFov(180.);
    this->Engine = std::make_unique<RayTracingRenderer>(opt);

    return true;
}

int AppRenderer::Execute() {
    SDL_Event event;

    if (Initialize() == false)
        return -1;

    while (this->IsRunning) {
        while (SDL_PollEvent(&event) != 0)
            HandleEvents(&event);
        DoLoop();
        Rendering();
    }

    Exiting();
    return 0;
}

void AppRenderer::HandleEvents(SDL_Event* event) {
    if (event->type == SDL_QUIT)
        IsRunning = false;
}

void AppRenderer::DoLoop() {
    double ratio = (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT;
    for (int y = 0; y < WINDOW_HEIGHT; ++y) {
        int x_floor = std::max((int)std::floor((double)y * ratio), 0);
        int x_ceil = std::min((int)std::ceil((double)y * ratio), WINDOW_WIDTH);

        this->ImageInstance.SetPixel(x_floor, y, 255, 255, 255);
        this->ImageInstance.SetPixel(x_ceil, y, 255, 255, 255);
    }
}

void AppRenderer::Rendering() {
    this->Engine->render();
    this->ImageInstance.Display();
    SDL_RenderPresent(this->Renderer);
}

void AppRenderer::Exiting() {
    SDL_DestroyRenderer(this->Renderer);
    SDL_DestroyWindow(this->Window);
    SDL_Quit();
}
