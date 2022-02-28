#include "Sample/GPUDriven.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <iostream>
LEARN_OPENGL_BEGIN
FGPUDriven::FGPUDriven(int Width, int Height, const char* Title)
	:FSample(Width, Height, Title)
{
}

FGPUDriven::~FGPUDriven()
{
	OnDestroy();
}

void FGPUDriven::OnInit()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw "Failed to initialize GLAD";
	}

	glViewport(0, 0, m_Width, m_Height);
}

void FGPUDriven::OnRender()
{
	glClearColor(0.4f, 0.6f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void FGPUDriven::OnUpdate()
{
	glViewport(0, 0, m_Width, m_Height);
}

void FGPUDriven::OnDestroy()
{
}
LEARN_OPENGL_END