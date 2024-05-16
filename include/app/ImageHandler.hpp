
#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <SDL2/SDL.h>

#define RGB_TO_ARGB888(red, green, blue) 0xFF000000 | (red << 16) | (green << 8) | blue

class ImageHandler
{
    public:
        ImageHandler();
        ~ImageHandler();

        void Initialize(const int xSize, const int ySize, SDL_Renderer *pRenderer);
        // Change a pixel color
        void SetPixel(const int x, const int y, const uint8_t red, const uint8_t green, const uint8_t blue);
        void Display();

    private:

        void InitColors();

        // Arrays to store image data.
        std::vector<uint32_t> PixelColor;
        int XSize, YSize = (0, 0);

        // SDL2 stuff.
        SDL_Renderer *RendererPtr = nullptr;
        SDL_Texture *TexturePtr = nullptr;

};