
#include <iostream>
#include <glad/glad.h>
#include "window.h"

Window::Window()
{
    std::cout << "Window constructor" << std::endl;
    engine.init();
}

Window::~Window()
{
    std::cout << "Window destructor" << std::endl;
}

void Window::init()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }
    window = glfwCreateWindow(640, 480, "Virtualization", NULL, NULL);
    if (!window)
    {
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    } else {
        std::cout << glGetString(GL_VERSION) << std::endl;
    }
    unsigned int id;
    glGenBuffers(1, &id);
}

void Window::display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.3f, 0.7f, 0.3f, 1.0f);
}

void Window::run()
{
    while (!glfwWindowShouldClose(window))
    {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}