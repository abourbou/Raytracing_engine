
#pragma once

#include <SDL2/SDL.h>
#include "ImageHandler.hpp"
#include "RaytracingRenderer.hpp"
#include "SceneOptions.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

class AppRenderer
{
    public:
        AppRenderer();

        int  Execute();
        bool Initialize();
        void HandleEvents(SDL_Event *event);
        void DoLoop();
        void Rendering();
        void Exiting();

    private:
        // Store the image which handle pixels
        ImageHandler ImageInstance;

        bool IsRunning = false;
        SDL_Renderer *Renderer = nullptr;
        SDL_Window *Window = nullptr;
        std::unique_ptr<RayTracingRenderer> Engine;
};