
#pragma once

#include <cstdint>
#include <exception>
#include <iostream>

#define GetMacro(name, type)                                                                       \
    type Get##name() const { return name; }

class InvalidInput : public std::exception {
  public:
    InvalidInput() : Msg("invalid input") {}
    InvalidInput(std::string input) : Msg("invalid input for " + input) {}

    virtual const char* what() const noexcept { return this->Msg.c_str(); }

  private:
    std::string Msg;
};

class SceneOptions {
  public:
    SceneOptions(){};
    SceneOptions(double fov, uint32_t widthScreen, uint32_t heightScreen);

    // Getter
    GetMacro(Fov, double);
    GetMacro(WidthScreen, uint32_t);
    GetMacro(HeightScreen, uint32_t);

    // Setter
    void SetFov(double fov);
    void SetWidthScreen(uint32_t WidthScreen);
    void SetHeightScreen(uint32_t WidthScreen);

  private:
    double Fov = 90.;
    uint32_t WidthScreen = 1280;
    uint32_t HeightScreen = 720;
};