#include "ImageHandler.hpp"
#include <fstream>

// The default constructor.
ImageHandler::ImageHandler() {}

// The destructor.
ImageHandler::~ImageHandler() {
    if (this->RendererPtr != NULL)
        SDL_DestroyRenderer(this->RendererPtr);
}

// Function to initialize.
void ImageHandler::Initialize(const int xSize, const int ySize, SDL_Renderer* pRenderer) {
    // Resize image data arrays.
    PixelColor.resize(xSize * ySize);

    // Store the dimensions.
    this->XSize = xSize;
    this->YSize = ySize;

    // Store the pointer to the renderer.
    this->RendererPtr = pRenderer;

    // Create texture used for pixels
    this->TexturePtr = SDL_CreateTexture(this->RendererPtr, SDL_PIXELFORMAT_ARGB8888,
                                         SDL_TEXTUREACCESS_STREAMING, this->XSize, this->YSize);
    this->InitColors();
}

// Function to set pixels.
void ImageHandler::SetPixel(const int x, const int y, const uint8_t red, const uint8_t green,
                            const uint8_t blue) {
    PixelColor.at(x + y * this->XSize) = RGB_TO_ARGB888(red, green, blue);
}

// Function to generate the display.
void ImageHandler::Display() {
    // Update the texture with the pixel buffer.
    SDL_UpdateTexture(this->TexturePtr, NULL, this->PixelColor.data(),
                      this->XSize * sizeof(uint32_t));

    SDL_RenderClear(this->RendererPtr);

    // Copy the texture to the renderer.
    SDL_RenderCopy(this->RendererPtr, this->TexturePtr, NULL, NULL);
}

void ImageHandler::InitColors() {
    for (int x = 0; x < this->XSize; ++x) {
        for (int y = 0; y < this->YSize; ++y) {
            this->PixelColor.at(x + y * this->XSize) = RGB_TO_ARGB888(0, 0, 0);
        }
    }
}
