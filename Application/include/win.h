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

#include <X11/Xlib.h>
#include <GL/glx.h>

class Win
{
public:
	Win() = delete;
	Win(Win&) = delete;
	Win(int width, int height, const char* name);
	Window getWin();
	void swapBuffer();
	bool status = true;
	~Win();
protected:
	Window window;
	Display* display;
	int screen;
private:
	GLXContext glxcontext;
	XVisualInfo vInfo;
};

#endif
