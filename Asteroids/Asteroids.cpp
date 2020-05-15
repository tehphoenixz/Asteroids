﻿// Asteroids.cpp : Defines the entry point for the application.
//

#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Other includes
#include "AsteroidsGame/AsteroidsGame.h"
#include "Engine/IO/IO.h"
#include "Engine/Window/Window.h"
#include "Engine/Timing/Timing.h"
#include "Engine/Texture/Texture.h"
#include "Engine/Text/Text.h"
#include "Engine/Text/Menu/Menu.h"
#include "Engine/Audio/Audio.h"
#include <string>

void Game(GLFWwindow* window);

int main() {
    glfwInit();
    GLFWwindow* window = Engine::CreateGameWindow(800, 800, "OpenGL", Engine::key_callback, Engine::mouse_callback, Engine::character_callback);
    Engine::Audio::LoadDeviceAndContext();
    Engine::Menu menu(
        {
            { "New Game", [window]() { Game(window); } },
            { "Options", Engine::Menu({
                { "Volume", &Engine::Audio::volume }
            }, true)},
            { "Quit", [window]() { glfwSetWindowShouldClose(window, true); } }
        }, false);
    while (!glfwWindowShouldClose(window)) {
        menu.Show(window);
    }
    glfwTerminate();
    Engine::Audio::UnloadDeviceAndContext();
    return 0;
}

void Game(GLFWwindow* window) {
    Engine::InputState inputState = {};
    void* oldInputState = glfwGetWindowUserPointer(window);
    glfwSetWindowUserPointer(window, (void*)(&inputState));
    Asteroids::AsteroidsGame game(10, 800, 800);
    Engine::GameTimer timer(0.01666667f);
    Engine::Shader textShader("./text");
    Engine::Texture font("./font.DDS");
    timer.Start();
    int i = 0;
    while (true) {
        timer.Tick();
        while (timer.ConsumeTick() && !glfwWindowShouldClose(window)) {
            glfwPollEvents();
            game.HandleEvents(inputState);
            game.Update(inputState);
        }
        if (glfwWindowShouldClose(window)) {
            glfwSetWindowUserPointer(window, oldInputState);
            glfwSetWindowShouldClose(window, false);
            break;
        }

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        game.DrawFrame();
        Engine::DrawString(font, textShader, -1.0f, 0.925f, 0.075f, "Score: " + std::to_string(game.GetScore()));
        glfwSwapBuffers(window);
    }
}