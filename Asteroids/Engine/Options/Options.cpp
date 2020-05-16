#include "Options.h"
#include "Engine/Audio/Audio.h"
#include <GLFW/glfw3.h>

namespace Engine {
    std::vector<Options::ScreenSize> Options::screenSizes = {
            { 640, 360 },
            { 800, 600 },
            { 1024, 768 },
            { 1280, 720 },
            { 1280, 800 },
            { 1280, 1024 },
            { 1360, 768 },
            { 1366, 768 },
            { 1440, 900 },
            { 1536, 864 },
            { 1600, 900 },
            { 1680, 1050 },
            { 1920, 1080 },
            { 1920, 1200 },
            { 2048, 1152 },
            { 2560, 1080 },
            { 2560, 1440 },
            { 3440, 1440 },
            { 3840, 2160 },
    };

    int screenSizeIndex = 12;
    Options::ScreenSize Options::screenSize = screenSizes[screenSizeIndex];
    int Options::volume = 5;

    Menu Options::GetOptionsMenu() {
        std::vector<Engine::MenuItem> menuItems = {};
        menuItems.push_back({ "Volume", &volume });
        menuItems.push_back({ "Increase Res", []() {ChangeResolution(true); } });
        menuItems.push_back({ "Decrease Res", []() {ChangeResolution(false); } });
        return Engine::Menu(menuItems, true);
    }

    void Options::ChangeResolution(bool increase) {
        GLFWwindow* window = glfwGetCurrentContext();
        if (increase) {
            screenSizeIndex++;
            if (screenSizeIndex >= screenSizes.size()) {
                screenSizeIndex--;
            }
            screenSize = screenSizes[screenSizeIndex];
            glfwSetWindowSize(window, screenSize.first, screenSize.second);
            glViewport(0, 0, screenSize.first, screenSize.second);
        } else {
            screenSizeIndex--;
            if (screenSizeIndex < 0) {
                screenSizeIndex++;
            }
            screenSize = screenSizes[screenSizeIndex];
            glfwSetWindowSize(window, screenSize.first, screenSize.second);
            glViewport(0, 0, screenSize.first, screenSize.second);
        }
    }
}