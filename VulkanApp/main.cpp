#define GLFW_INCLUDE_VULKAN
#include"first_app.h"

#include<GLFW/glfw3.h>
#include<vulkan/vulkan.h>
#include<iostream>
#include<string>
#include<stdexcept>
#include<cstdlib>

int main() {
    lve::FirstApp app;
    try {
        app.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}