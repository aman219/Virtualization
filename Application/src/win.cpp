#include "win.h"

#ifdef _WIN64
Win::Win(int width, int height, const char* name)
{
	if (!glfwInit())
	{
		std::cout << "Unable to start glfw";
	}
	window = glfwCreateWindow(width, height, name, NULL, NULL);
	glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "unable to start opengl\n";
	}
	std::cout << "opengl version : " << glGetString(GL_VERSION) << "\n";
	glfwSwapInterval(1);
}

GLFWwindow* Win::getWin()
{
	return window;
}


void Win::swapBuffer()
{
	glfwPollEvents();
	glfwSwapBuffers(window);
}

Win::~Win()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

#elif __linux
	
#endif
