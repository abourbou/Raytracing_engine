
#include <iostream>

//TODO Use a linter

#include "AppRenderer.hpp"

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
