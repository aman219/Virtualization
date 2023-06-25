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


Win::Win(int width, int height, const char* name)
{
	display = XOpenDisplay(nullptr);
	screen = DefaultScreen(display);

	XMatchVisualInfo(display, screen, 32, TrueColor, &vInfo);

	window = XCreateSimpleWindow(display, RootWindow(display, screen), 0, 0, width, height, 0, 0xffffff, 0x000000);
	XStoreName(display, window, "Virualization");

	GLXContext glcontext = glXCreateContext(display, &vInfo, 0, true);
    glXMakeCurrent(display, window, glcontext);

	XMapWindow(display, window);
	if (!gladLoadGL())
	{
        std::cout << "Error while statring opengl\n";
    }
    else
    {
        std::cout << "Opengl Version : " << glGetString(GL_VERSION) << "\n";
    }

}

Window Win::getWin()
{
	return window;
}

void Win::swapBuffer()
{
	glXSwapBuffers(display, window);
}

Win::~Win()
{
	std::cout << "This is window destructor\n";
}

#endif
