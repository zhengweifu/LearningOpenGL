#include "Core/Camera/PerspectiveCamera.h"
#include <glm/gtc/matrix_transform.hpp>

LEARN_OPENGL_BEGIN

FPerspectiveCamera::FPerspectiveCamera()
	: FCamera()
	, m_Fov(45.0f)
	, m_Ratio(0.5f)
	, m_NearClip(0.1f)
	, m_FarClip(1000.0f)
{
}

FPerspectiveCamera::FPerspectiveCamera(float Fov, float Ratio, float NearClip, float FarClip)
	: FCamera()
	, m_Fov(Fov)
	, m_Ratio(Ratio)
	, m_NearClip(NearClip)
	, m_FarClip(FarClip)
{
}

glm::mat4& FPerspectiveCamera::UpdateProjectionMatrix()
{
	m_ProjectionMatrix = glm::perspective(glm::radians(m_Fov), m_Ratio, m_NearClip, m_FarClip);
	return m_ProjectionMatrix;
}

LEARN_OPENGL_END
