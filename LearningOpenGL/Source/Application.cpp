#include "Application.h"
#include "Sample/Sample.h"

LEARN_OPENGL_BEGIN
FSample* FApplication::s_Sample = nullptr;
GLFWwindow* FApplication::s_GLFWWindow = nullptr;

void FApplication::Run(FSample& Sample)
{
	s_Sample = &Sample;
	FApplication::_CreateWindow(Sample.m_Width, Sample.m_Height, Sample.m_Title.c_str());
	
	glfwMakeContextCurrent(s_GLFWWindow); // Initialize GLEW

	// init
	Sample.OnInit();

	glfwSetFramebufferSizeCallback(s_GLFWWindow, FApplication::_FramebufferSizeCallback);


	while (!glfwWindowShouldClose(s_GLFWWindow))
	{
		// input
		//ProcessInput();

		// render
		Sample.OnRender();

		glfwSwapBuffers(s_GLFWWindow);
		glfwPollEvents();
	}
	// destory
	Sample.OnDestroy();
	glfwTerminate();
}

void FApplication::_CreateWindow(const int& Width, const int& Height, const char* Title)
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	s_GLFWWindow = glfwCreateWindow(Width, Height, Title, NULL, NULL);
	if (s_GLFWWindow == NULL) {
		glfwTerminate();
		throw "Failed to create window.";
	}

	glfwMakeContextCurrent(s_GLFWWindow); // Initialize GLEW

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		throw "Failed to initialize GLAD";
	}
}

void FApplication::_FramebufferSizeCallback(GLFWwindow* Window, int Width, int Height)
{
	if (s_Sample)
	{
		s_Sample->OnUpdate();
	}
	//glViewport(0, 0, Width, Height);
}

//void FApplication::ProcessInput()
//{
//	if (glfwGetKey(s_GLFWWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(s_GLFWWindow, true);
//	}
//}
LEARN_OPENGL_END
