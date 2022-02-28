#include "Sample/Triangle.h"

#include <glad/glad.h>
#include "glfw/glfw3.h"

#include <iostream>

LEARN_OPENGL_BEGIN
FTriangle::FTriangle(int Width, int Height, const char* Title)
	:FSample(Width, Height, Title)
{
}

FTriangle::~FTriangle()
{
	OnDestroy();
}

void FTriangle::OnInit()
{
	glViewport(0, 0, m_Width, m_Height);

	// 顶点着色器
	const char* VertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	GLuint VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertexShader, 1, &VertexShaderSource, NULL);
	glCompileShader(VertexShader);

	int success;
	char InfoLog[512];
	glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(VertexShader, 512, NULL, InfoLog);
		std::cout << "Failed to compile vertex shader:\n" << InfoLog << std::endl;
	}

	// 片元着色器
	const char* FragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";
	GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragmentShader, 1, &FragmentShaderSource, NULL);
	glCompileShader(FragmentShader);

	glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(VertexShader, 512, NULL, InfoLog);
		std::cout << "Failed to compile fragment shader:\n" << InfoLog << std::endl;
	}

	// 创建着色器程序并链接
	m_ShaderProgram = glCreateProgram();
	glAttachShader(m_ShaderProgram, VertexShader);
	glAttachShader(m_ShaderProgram, FragmentShader);
	glLinkProgram(m_ShaderProgram);
	glGetProgramiv(m_ShaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(m_ShaderProgram, 512, NULL, InfoLog);
		std::cout << "Failed to link shader:\n" << InfoLog << std::endl;
	}
	// 删除着色器
	glDeleteShader(VertexShader);
	glDeleteShader(FragmentShader);

	// 定义三角形数据
	float Vertices[] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f
	};

	// 创建VAO
	glGenVertexArrays(1, &m_VAO);
	// 创建VBO
	glGenBuffers(1, &m_VBO);
	// 绑定VAO
	glBindVertexArray(m_VAO);
	// VBO绑定到GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	// 申请VBO显存
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	// layout 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void FTriangle::OnRender()
{
	glClearColor(0.4f, 0.6f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(m_ShaderProgram);
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void FTriangle::OnUpdate()
{
	glViewport(0, 0, m_Width, m_Height);
}

void FTriangle::OnDestroy()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
	glDeleteProgram(m_ShaderProgram);
}
LEARN_OPENGL_END