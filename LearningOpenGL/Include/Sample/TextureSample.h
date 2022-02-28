#pragma once
#include "Sample/Sample.h"
#include "Core/Shader.h"

#include <memory>

LEARN_OPENGL_BEGIN
class FTextureSample : public FSample
{
public:
	FTextureSample(int Width, int Height, const char* Title);
	~FTextureSample();
	virtual void OnInit() override;
	virtual void OnRender() override;
	virtual void OnUpdate() override;
	virtual void OnDestroy() override;
private:
	unsigned int m_VBO;
	unsigned int m_IBO;
	unsigned int m_VAO;
	std::shared_ptr<FShader> p_Shader;
	unsigned int m_Texture;
};
LEARN_OPENGL_END