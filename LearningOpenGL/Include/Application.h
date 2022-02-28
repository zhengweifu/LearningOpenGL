#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "Env.h"

LEARN_OPENGL_BEGIN
class FApplication
{
public:
	static void Run(class FSample& Sample);
private:
	static void _CreateWindow(const int& Width, const int& Height, const char* Title);
	static void _FramebufferSizeCallback(GLFWwindow* Window, int Width, int Height);
private:
	static GLFWwindow* s_GLFWWindow;
	static FSample* s_Sample;
};
LEARN_OPENGL_END