#include "Core/Camera/Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

LEARN_OPENGL_BEGIN

glm::vec3 FCamera::s_UP = glm::vec3(0.0f, 1.0f, 0.0f);

FCamera::~FCamera()
{
}

void FCamera::LookAt(const glm::vec3& Target)
{
	m_Target = Target;
	UpdateViewMatrix();
}

glm::mat4& FCamera::UpdateViewMatrix()
{
	glm::vec3 EyeDir = glm::normalize(m_Position - m_Target);
	glm::vec3 RightDir = glm::normalize(glm::cross(s_UP, EyeDir));
	glm::vec3 UpDir = glm::normalize(glm::cross(EyeDir, RightDir));
	m_ViewMatrix = glm::lookAt(m_Position, m_Target, UpDir);
	return m_ViewMatrix;
}

FCamera::FCamera()
{
	m_Position = glm::vec3(0.0f, 0.0f, 1.0f);
	m_Target = glm::vec3(0.0f, 0.0f, 0.0f);
	UpdateViewMatrix();
}

LEARN_OPENGL_END
