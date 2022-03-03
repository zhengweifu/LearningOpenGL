#pragma once
#include "Env.h"
#include <glm/vec3.hpp>
#include <glm/matrix.hpp>
LEARN_OPENGL_BEGIN
class FCamera
{
public:
	virtual ~FCamera();
	glm::mat4 GetViewMatrix() const { return m_ViewMatrix; }
	void LookAt(const glm::vec3& Target);
	glm::mat4& UpdateViewMatrix();
protected:
	FCamera();
public:
	glm::vec3 m_Position;
	glm::vec3 m_Target;
private:
	glm::mat4 m_ViewMatrix;
	static glm::vec3 s_UP;
};
LEARN_OPENGL_END