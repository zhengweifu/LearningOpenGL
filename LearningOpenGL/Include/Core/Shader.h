#pragma once
#include <string>
#include "Env.h"
#include <glm/glm.hpp>
LEARN_OPENGL_BEGIN
class FShader
{
public:
	FShader(const std::wstring& VertexPath, const std::wstring& FragmentPath);
	void Use();
	void Set(const char* Name, bool Value) const;
	void Set(const char* Name, int Value) const;
	void Set(const char* Name, float Value) const;
	void Set(const char* Name, glm::vec2 Value) const;
	void Set(const char* Name, glm::vec3 Value) const;
	void Set(const char* Name, glm::vec4 Value) const;
	void Set(const char* Name, glm::mat2 Value) const;
	void Set(const char* Name, glm::mat3 Value) const;
	void Set(const char* Name, glm::mat4 Value) const;
	void Destroy();
	unsigned int GetProgramId() const { return m_ProgramId; }
private:
	FShader() = default;
private:
	unsigned int m_ProgramId;
};
LEARN_OPENGL_END