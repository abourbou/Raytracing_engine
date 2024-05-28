
#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <vector>

#include "engineTools.hpp"

class ImageHandler {
  public:
    ImageHandler();
    ~ImageHandler();

    void Initialize(const int xSize, const int ySize, SDL_Renderer* pRenderer);
    // Change a pixel color
    void SetPixel(const int x, const int y, const uint8_t red,
                  const uint8_t green, const uint8_t blue);
    void SetPixel(const int x, const int y, const uint32_t color);

    void Display();

  private:
    void InitColors();

    // Arrays to store image data.
    std::vector<uint32_t> PixelColor;
    int XSize, YSize = (0, 0);

    // SDL2 stuff.
    SDL_Renderer* RendererPtr = nullptr;
    SDL_Texture* TexturePtr = nullptr;
};