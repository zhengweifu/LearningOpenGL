#pragma once
#include <string>
#include "Env.h"
LEARN_OPENGL_BEGIN
class FShader
{
public:
	FShader(const std::wstring& VertexPath, const std::wstring& FragmentPath);
	void Use();
	void Set(const char* Name, bool Value) const;
	void Set(const char* Name, int Value) const;
	void Set(const char* Name, float Value) const;
	void Destroy();
	unsigned int GetProgramId() const { return m_ProgramId; }
private:
	FShader() = default;
private:
	unsigned int m_ProgramId;
};
LEARN_OPENGL_END