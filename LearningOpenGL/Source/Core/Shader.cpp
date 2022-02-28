#include "Core/Shader.h"
#include "Util/StringUtil.h"

#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

LEARN_OPENGL_BEGIN
static void CreateAndCheckShader(
	const char* ShaderCode,
	const bool& bVertexShader,
	GLuint& OutShader)
{
	OutShader = glCreateShader(bVertexShader ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
	glShaderSource(OutShader, 1, &ShaderCode, NULL);
	glCompileShader(OutShader);

	int success;
	char InfoLog[512];
	glGetShaderiv(OutShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(OutShader, 512, NULL, InfoLog);
		std::cout << "Failed to compile " << (bVertexShader ? "vertex" : "fragment") << " shader : \n" << InfoLog << std::endl;
	}
}

FShader::FShader(const std::wstring& VertexPath, const std::wstring& FragmentPath)
{
	std::wstring VertexCode, FragmentCode;
	std::wifstream VertexShaderFile, FragmentShaderFile;
	VertexShaderFile.exceptions(std::wifstream::failbit | std::wifstream::badbit);
	FragmentShaderFile.exceptions(std::wifstream::failbit | std::wifstream::badbit);
	try
	{
		VertexShaderFile.open(VertexPath);
		FragmentShaderFile.open(FragmentPath);
		std::wstringstream VertexShaderStream, FragmentShaderStream;
		VertexShaderStream << VertexShaderFile.rdbuf();
		FragmentShaderStream << FragmentShaderFile.rdbuf();

		VertexShaderFile.close();
		FragmentShaderFile.close();

		VertexCode = VertexShaderStream.str();
		FragmentCode = FragmentShaderStream.str();
	}
	catch (std::wifstream::failure e)
	{
		throw "";
	}
	std::string VertCode = FStringUtil::ws2s(VertexCode);
	std::string FragCode = FStringUtil::ws2s(FragmentCode);
	const char* VertexShaderCode = VertCode.c_str();
	const char* FragmentShaderCode = FragCode.c_str();

	GLuint VertexShader, FragmentShader;
	CreateAndCheckShader(VertexShaderCode, true, VertexShader);
	CreateAndCheckShader(FragmentShaderCode, false, FragmentShader);

	// ������ɫ����������
	int success;
	char InfoLog[512];
	m_ProgramId = glCreateProgram();
	glAttachShader(m_ProgramId, VertexShader);
	glAttachShader(m_ProgramId, FragmentShader);
	glLinkProgram(m_ProgramId);
	glGetProgramiv(m_ProgramId, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(m_ProgramId, 512, NULL, InfoLog);
		std::cout << "Failed to link shader:\n" << InfoLog << std::endl;
	}

	// ɾ����ɫ��
	glDeleteShader(VertexShader);
	glDeleteShader(FragmentShader);
}

void FShader::Use()
{
	glUseProgram(m_ProgramId);
}

void FShader::Set(const char* Name, bool Value) const
{
	glUniform1i(glGetUniformLocation(m_ProgramId, Name), (int)Value);
}

void FShader::Set(const char* Name, int Value) const
{
	glUniform1i(glGetUniformLocation(m_ProgramId, Name), Value);
}

void FShader::Set(const char* Name, float Value) const
{
	glUniform1f(glGetUniformLocation(m_ProgramId, Name), Value);
}

void FShader::Destroy()
{
	glDeleteProgram(m_ProgramId);
}
LEARN_OPENGL_END