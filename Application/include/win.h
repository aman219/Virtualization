#pragma once
#include <iostream>
#include "glad/glad.h"

#ifdef _WIN64
	#include "GLFW/glfw3.h"
class Win
{
public:
	Win() = delete;
	Win(Win&) = delete;
	Win(int width, int height, const char* name);
	GLFWwindow* getWin();
	void swapBuffer();
	bool status = true;
	~Win();
protected:
	GLFWwindow* window;
private:

};
#elif __linux
	#include <X11/xlib.h>
#endif
