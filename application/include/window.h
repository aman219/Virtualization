#pragma once

#include <GLFW/glfw3.h>
#include "engine.h"

class Window
{
public:
    Window();
    ~Window();
    void init();
    void display();
    void run();
private:
    GLFWwindow *window;
    Engine engine;
};