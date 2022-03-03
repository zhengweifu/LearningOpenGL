#include "Sample/CameraSample.h"
#include "Util/StringUtil.h"
#include "Core/Camera/PerspectiveCamera.h"
#include "Core/Geometry.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <stb_image.h>
#include <glm/gtx/string_cast.hpp>

#include <iostream>
LEARN_OPENGL_BEGIN
FCameraSample::FCameraSample(int Width, int Height, const char* Title)
	:FSample(Width, Height, Title)
{
}

FCameraSample::~FCameraSample()
{
	OnDestroy();
}

void FCameraSample::OnInit()
{
	glViewport(0, 0, m_Width, m_Height);

	std::wstring VertexShaderPath = m_AssetsPath + L"Resource\\Shader\\CameraSample\\VS.glsl";
	std::wstring FragmentShaderPath = m_AssetsPath + L"Resource\\Shader\\CameraSample\\FS.glsl";
	p_Shader = std::make_shared<FShader>(VertexShaderPath, FragmentShaderPath);

	FPerspectiveCamera Camera(45.0f, (float)m_Width / (float)m_Height, 0.01f, 1000.f);
	Camera.m_Position = glm::vec3(0, 0, 5);
	glm::mat4& ViewMatrix = Camera.UpdateViewMatrix();
	glm::mat4& ProjectionMatrix = Camera.UpdateProjectionMatrix();

	std::cout << glm::to_string(ViewMatrix) << std::endl;
	std::cout << glm::to_string(ProjectionMatrix) << std::endl;

	glm::mat4 mm = ProjectionMatrix * ViewMatrix;
	std::cout << glm::to_string(mm) << std::endl;

	std::vector<FVertex> Vertices;
	Vertices.push_back({ glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0.0f, 0.0f) });
	Vertices.push_back({ glm::vec3( 0.5f, -0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(1.0f, 0.0f) });
	Vertices.push_back({ glm::vec3( 0.5f,  0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(1.0f, 1.0f) });
	Vertices.push_back({ glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec3(0, 0, 1), glm::vec2(0.0f, 1.0f) });
	std::vector<unsigned int> Indices = {
		0, 1, 2,
		0, 2, 3
	};
	p_Geometry = std::make_shared<FGeometry>(Vertices, Indices);

	// 创建纹理
	glGenTextures(1, &m_Texture);
	glBindTexture(GL_TEXTURE_2D, m_Texture);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	std::string TexturePath = FStringUtil::ws2s(m_AssetsPath + L"Resource\\Texture\\container.jpg");
	int TextureWidth, TextureHeight, TextureChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* TextureData = stbi_load(TexturePath.c_str(), &TextureWidth, &TextureHeight, &TextureChannels, 0);
	if (TextureData)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TextureWidth, TextureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureData);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture." << std::endl;
	}
	stbi_image_free(TextureData);

	p_Shader->Use();
	p_Shader->Set("BaseTexture", 0);

	// p_Shader->Set 执行前需要先执行 p_Shader->Use();
	p_Shader->Set("uProjectionMatrix", ProjectionMatrix);
	p_Shader->Set("uViewMatrix", ViewMatrix);
}

void FCameraSample::OnRender()
{
	glClearColor(0.4f, 0.6f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE0, m_Texture);

	glUseProgram(p_Shader->GetProgramId());
	p_Geometry->Draw();
}

void FCameraSample::OnUpdate()
{
	glViewport(0, 0, m_Width, m_Height);
}

void FCameraSample::OnDestroy()
{
	p_Shader->Destroy();
	p_Geometry->Destroy();
}
LEARN_OPENGL_END