#pragma once
#include <string>
#include "Env.h"

#include <glm/glm.hpp>

#include <vector>

LEARN_OPENGL_BEGIN
struct FVertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 UV;
};

class FGeometry
{
public:
	FGeometry(std::vector<FVertex> Vertices, std::vector<unsigned int> Indices);
	void Destroy();
	void Draw();
private:
	void Setup();
public:
	std::vector<FVertex> m_Vertices;
	std::vector<unsigned int> m_Indices;
	unsigned int m_VAO;
private:
	unsigned int m_VBO;
	unsigned int m_IBO;
};
LEARN_OPENGL_END