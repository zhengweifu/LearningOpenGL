#pragma once
#include "Sample.h"

LEARN_OPENGL_BEGIN
class FTriangle : public FSample
{
public:
	FTriangle(int Width, int Height, const char* Title);
	~FTriangle();
	virtual void OnInit() override;
	virtual void OnRender() override;
	virtual void OnUpdate() override;
	virtual void OnDestroy() override;
private:
	unsigned int m_VBO;
	unsigned int m_VAO;
	unsigned int m_ShaderProgram;
};
LEARN_OPENGL_END