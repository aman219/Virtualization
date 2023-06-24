
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "../../Engine/include/engine.h"

int main()
{
	GLFWwindow* window;
	if (!glfwInit())
		return -1;
	window = glfwCreateWindow(640, 480, "Virtualization", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "unable to create window\n";
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	std::cout << "Version : " << glGetString(GL_VERSION);
	Engine e;
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.1f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}