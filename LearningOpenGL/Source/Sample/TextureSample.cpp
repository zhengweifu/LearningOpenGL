#include "Sample/TextureSample.h"
#include "Util/StringUtil.h"

#include <glad/glad.h>
#include <glfw/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <iostream>
LEARN_OPENGL_BEGIN
FTextureSample::FTextureSample(int Width, int Height, const char* Title)
	:FSample(Width, Height, Title)
{
}

FTextureSample::~FTextureSample()
{
	OnDestroy();
}

void FTextureSample::OnInit()
{
	glViewport(0, 0, m_Width, m_Height);

	std::wstring VertexShaderPath = m_AssetsPath + L"Resource\\Shader\\TextureSample\\VS.glsl";
	std::wstring FragmentShaderPath = m_AssetsPath + L"Resource\\Shader\\TextureSample\\FS.glsl";
	p_Shader = std::make_shared<FShader>(VertexShaderPath, FragmentShaderPath);

	// 定义模型数据
	float Vertices[] = {
		// vertices          // uv
		-0.5f, -0.5f, 0.0f,  0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f,  0.0f, 1.0f
	};

	int Indices[] = {
		0, 1, 2,
		0, 2, 3
	};

	// 创建VAO
	glGenVertexArrays(1, &m_VAO);
	// 创建VBO
	glGenBuffers(1, &m_VBO);
	// 创建IBO
	glGenBuffers(1, &m_IBO);

	// 绑定VAO
	glBindVertexArray(m_VAO);

	// VBO绑定到GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	// 申请VBO显存
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);

	// layout 0
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// layout 1
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

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
}

void FTextureSample::OnRender()
{
	glClearColor(0.4f, 0.6f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE0, m_Texture);

	glUseProgram(p_Shader->GetProgramId());
	glBindVertexArray(m_VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void FTextureSample::OnUpdate()
{
	glViewport(0, 0, m_Width, m_Height);
}

void FTextureSample::OnDestroy()
{
	glDeleteVertexArrays(1, &m_VAO);
	glDeleteBuffers(1, &m_VBO);
	p_Shader->Destroy();
}
LEARN_OPENGL_END