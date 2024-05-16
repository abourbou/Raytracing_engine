
#include <iostream>

//TODO Use a linter
//TODO create exception and replace assert by it

#include "AppRenderer.hpp"
#include "Camera.hpp"

int main(int argc, char **argv)
{
    AppRenderer app;
    if (app.Execute() == -1)
    {
        std::cout << "Error: execution of the app failed" << std::endl;
        return 1;
    }

    return 0;
}
