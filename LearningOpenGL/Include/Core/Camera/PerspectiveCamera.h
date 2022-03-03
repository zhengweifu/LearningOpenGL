#pragma once
#include <string>
#include "Env.h"
#include "Core/Camera/Camera.h"

LEARN_OPENGL_BEGIN
class FPerspectiveCamera : public FCamera
{
public:
	FPerspectiveCamera();
	FPerspectiveCamera(float Fov, float Ratio, float NearClip, float FarClip);
	glm::mat4& UpdateProjectionMatrix();
public:
	float m_Fov;
	float m_Ratio;
	float m_NearClip;
	float m_FarClip;
private:
	glm::mat4 m_ProjectionMatrix;
};
LEARN_OPENGL_END