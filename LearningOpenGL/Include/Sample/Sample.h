#pragma once
#include <windows.h>
#include <string>

#include "Env.h"

LEARN_OPENGL_BEGIN

class FSample
{
public:
	FSample(int Width, int Height, const char* Title);
	virtual ~FSample();
	virtual void OnInit() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnDestroy() = 0;
private:
	FSample() = default;
public:
	int m_Width;
	int m_Height;
	std::string m_Title;
protected:
	// Root assets path.
	std::wstring m_AssetsPath;
};

LEARN_OPENGL_END