
#include <exception>
#include <iostream>

// TODO Create tests

#include "AppRenderer.hpp"
#include "Camera.hpp"

int main(int argc, char** argv) {
    try {
        AppRenderer app;
        if (app.Execute() == -1) {
            std::cerr << "Error: execution of the app failed" << std::endl;
            return 1;
        }
    } catch (std::exception& e) {
        std::cerr << "Error : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
