#pragma once
#include "Sample/Sample.h"
LEARN_OPENGL_BEGIN
class FGPUDriven : public FSample
{
public:
	FGPUDriven(int Width, int Height, const char* Title);
	~FGPUDriven();
	virtual void OnInit() override;
	virtual void OnRender() override;
	virtual void OnUpdate() override;
	virtual void OnDestroy() override;
};
LEARN_OPENGL_END